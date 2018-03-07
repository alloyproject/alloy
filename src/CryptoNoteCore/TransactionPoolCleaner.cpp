/*
 * Copyright (c) 2017-2018, The Alloy Developers.
 * Portions Copyright (c) 2012-2017, The CryptoNote Developers, The Bytecoin Developers.
 *
 * This file is part of Alloy.
 *
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE', which is part of this source code package.
 */

#include "TransactionPoolCleaner.h"
#include "CryptoNoteConfig.h"


#include "Common/StringTools.h"

#include <System/InterruptedException.h>
#include <System/Timer.h>

namespace CryptoNote {

TransactionPoolCleanWrapper::TransactionPoolCleanWrapper(
  std::unique_ptr<ITransactionPool>&& transactionPool,
  std::unique_ptr<ITimeProvider>&& timeProvider,
  Logging::ILogger& logger,
  uint64_t timeout)
  :
  transactionPool(std::move(transactionPool)),
  timeProvider(std::move(timeProvider)),
  logger(logger, "TransactionPoolCleanWrapper"),
  timeout(timeout) {

  assert(this->timeProvider);
}

TransactionPoolCleanWrapper::~TransactionPoolCleanWrapper() {
}

bool TransactionPoolCleanWrapper::pushTransaction(CachedTransaction&& tx, TransactionValidatorState&& transactionState) {
  return !isTransactionRecentlyDeleted(tx.getTransactionHash()) && transactionPool->pushTransaction(std::move(tx), std::move(transactionState));
}

const CachedTransaction& TransactionPoolCleanWrapper::getTransaction(const Crypto::Hash& hash) const {
  return transactionPool->getTransaction(hash);
}

bool TransactionPoolCleanWrapper::removeTransaction(const Crypto::Hash& hash) {
  return transactionPool->removeTransaction(hash);
}

size_t TransactionPoolCleanWrapper::getTransactionCount() const {
  return transactionPool->getTransactionCount();
}

std::vector<Crypto::Hash> TransactionPoolCleanWrapper::getTransactionHashes() const {
  return transactionPool->getTransactionHashes();
}

bool TransactionPoolCleanWrapper::checkIfTransactionPresent(const Crypto::Hash& hash) const {
  return transactionPool->checkIfTransactionPresent(hash);
}

const TransactionValidatorState& TransactionPoolCleanWrapper::getPoolTransactionValidationState() const {
  return transactionPool->getPoolTransactionValidationState();
}

std::vector<CachedTransaction> TransactionPoolCleanWrapper::getPoolTransactions() const {
  return transactionPool->getPoolTransactions();
}

uint64_t TransactionPoolCleanWrapper::getTransactionReceiveTime(const Crypto::Hash& hash) const {
  return transactionPool->getTransactionReceiveTime(hash);
}

std::vector<Crypto::Hash> TransactionPoolCleanWrapper::getTransactionHashesByPaymentId(const Crypto::Hash& paymentId) const {
  return transactionPool->getTransactionHashesByPaymentId(paymentId);
}

std::vector<Crypto::Hash> TransactionPoolCleanWrapper::clean() {
  try {

  uint64_t currentTime = timeProvider->now();
  std::vector<Crypto::Hash> deletedTransactions;
  auto transactionHashes = transactionPool->getTransactionHashes();  


 //this will clean out mempool TX's based on size
/*  
std::vector<CachedTransaction> poolTransactions = transactionPool->getPoolTransactions();
    for (auto it = poolTransactions.rbegin(); it != poolTransactions.rend(); ++it) {
    const CachedTransaction& transaction = *it;
    auto transactionBlobSize = transaction.getTransactionBinaryArray().size();
    auto hash=transaction.getTransactionHash();

    if (transactionBlobSize > ALLOY_TRANSACTION_SIZE_LIMIT) {
      logger(Logging::INFO) << "Cleaner Deleting transaction size: "  << transactionBlobSize
      << ", hash: " << Common::podToHex(hash) << "  from pool";

      recentlyDeletedTransactions.emplace(hash, currentTime);
      transactionPool->removeTransaction(hash);
      deletedTransactions.emplace_back(std::move(hash));
     }
   }
*/
  

  for (const auto& hash: transactionHashes) {
    uint64_t transactionAge = currentTime - transactionPool->getTransactionReceiveTime(hash);
    if (transactionAge >= timeout) {
      logger(Logging::INFO) << "Deleting transaction " << Common::podToHex(hash) << " from pool after timeout:"<<timeout;
      recentlyDeletedTransactions.emplace(hash, currentTime);
      transactionPool->removeTransaction(hash);
      deletedTransactions.emplace_back(std::move(hash));
    }
  }

    cleanRecentlyDeletedTransactions(currentTime);
    return deletedTransactions;
  } catch (System::InterruptedException&) {
    throw;
  } catch (std::exception& e) {
    logger(Logging::WARNING) << "Caught an exception: " << e.what() << ", stopping cleaning procedure cycle";
    throw;
  }
}

bool TransactionPoolCleanWrapper::isTransactionRecentlyDeleted(const Crypto::Hash& hash) const {
  auto it = recentlyDeletedTransactions.find(hash);
  return it != recentlyDeletedTransactions.end() && it->second >= timeout;
}

void TransactionPoolCleanWrapper::cleanRecentlyDeletedTransactions(uint64_t currentTime) {
  for (auto it = recentlyDeletedTransactions.begin(); it != recentlyDeletedTransactions.end();) {
    if (currentTime - it->second >= timeout) {
      it = recentlyDeletedTransactions.erase(it);
    } else {
      ++it;
    }
  }
}

}
