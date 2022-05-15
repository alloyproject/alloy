# Alloy

Copyright (c) 2017-2018, The Alloy Developers.   
Portions Copyright (c) 2012-2017, The CryptoNote Developers, The Bytecoin Developers.


Source Code
https://github.com/alt-coin-xao


# How to Compile

```sudo apt-get -y install build-essential libssl-dev libboost-all-dev```

```sudo apt-get -y install gcc-4.8 g++-4.8  git cmake```

```git clone https://github.com/alloyproject/alloy```

```cd alloy```

```mkdir build ; cd build```

```cmake ..```

```make```




## Introduction

Alloy is a private, secure, untraceable, decentralised digital currency. You are your bank, you control your funds, and nobody can trace your transfers unless you allow them to do so.

**Privacy:** Alloy uses a cryptographically sound system to allow you to send and receive funds without your transactions being easily revealed on the blockchain (the ledger of transactions that everyone has). This ensures that your purchases, receipts, and all transfers remain absolutely private by default.

**Security:** Using the power of a distributed peer-to-peer consensus network, every transaction on the network is cryptographically secured. Individual wallets have a 25 word mnemonic seed that is only displayed once, and can be written down to backup the wallet. Wallet files are encrypted with a passphrase to ensure they are useless if stolen.

**Untraceability:** By taking advantage of ring signatures, a special property of a certain type of cryptography, Alloy is able to ensure that transactions are not only untraceable, but have an optional measure of ambiguity that ensures that transactions cannot easily be tied back to an individual user or computer.

## About this Project

This is the core implementation of Alloy. It is open source and completely free to use without restrictions, except for those specified in the license agreement below. There are no restrictions on anyone creating an alternative implementation of Alloy that uses the protocol and network in a compatible manner.

As with many development projects, the repository on Github is considered to be the "staging" area for the latest changes. Before changes are merged into that branch on the main repository, they are tested by individual developers in their own branches, submitted as a pull request, and then subsequently tested by contributors who focus on testing and code reviews. That having been said, the repository should be carefully considered before using it in a production environment, unless there is a patch in the repository for a particular show-stopping issue you are experiencing. It is generally a better idea to use a tagged release for stability.

**Anyone is welcome to contribute to Alloy's codebase!** If you have a fix or code change, feel free to submit it as a pull request directly to the "master" branch. In cases where the change is relatively small or does not affect other parts of the codebase it may be merged in immediately by any one of the collaborators. On the other hand, if the change is particularly large or complex, it is expected that it will be discussed at length either well in advance of the pull request being submitted, or even directly on the pull request.

# License

Alloy is licensed under the "MIT License", see [LICENSE](LICENSE) for more info.
