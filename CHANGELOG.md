# [0.21.1](https://github.com/dashevo/dapi-grpc/compare/v0.20.0...v0.21.0) (2021-10-12)


### Bug Fixes

* cannot read properties of undefined (reading 'MethodInfo') ([#152](https://github.com/dashevo/dapi-grpc/pull/152))



# [0.21.0](https://github.com/dashevo/dapi-grpc/compare/v0.20.0...v0.21.0) (2021-10-12)


### Features

* support returning of a multiproof ([#127](https://github.com/dashevo/dapi-grpc/issues/127))
* implement getConsensusParams method ([#126](https://github.com/dashevo/dapi-grpc/issues/126), [#130](https://github.com/dashevo/dapi-grpc/issues/130), [#132](https://github.com/dashevo/dapi-grpc/issues/132), [#134](https://github.com/dashevo/dapi-grpc/issues/134))


### Bug Fixes

* height type was uint32 instead of int64 ([#123](https://github.com/dashevo/dapi-grpc/issues/123))


### BREAKING CHANGES

* `getStoreTreeProof` now returns `StoreTreeProof` message instead of `Buffer`



# [0.20.0](https://github.com/dashevo/dapi-grpc/compare/v0.19.0...v0.20.0) (2021-07-08)


### Features

* add additional information to `GetTransactionResponse` ([#118](https://github.com/dashevo/dapi-grpc/issues/118), [#120](https://github.com/dashevo/dapi-grpc/issues/120))
* add metadata and additional info to platform proofs ([#115](https://github.com/dashevo/dapi-grpc/issues/115), [#114](https://github.com/dashevo/dapi-grpc/issues/114), [#112](https://github.com/dashevo/dapi-grpc/issues/112))



# [0.19.0](https://github.com/dashevo/dapi-grpc/compare/v0.18.0...v0.19.0) (2021-04-30)


### Features

* restructure core status response ([#107](https://github.com/dashevo/dapi-grpc/issues/107))


### BREAKING CHANGES

* structure of `getStatus` method response has changed and not compatible with the previous version.



# [0.18.0](https://github.com/dashevo/dapi-grpc/compare/v0.17.0...v0.18.0) (2021-03-03)


### Bug Fixes

* lock file contained not patched protobufjs ([#104](https://github.com/dashevo/dapi-grpc/issues/104))


### Features


* `waitForStateTransitionResult` endpoint ([#99](https://github.com/dashevo/dapi-grpc/issues/99), [#101](https://github.com/dashevo/dapi-grpc/issues/101))



# [0.17.0](https://github.com/dashevo/dapi-grpc/compare/v0.16.0...v0.17.0) (2020-12-29)


### Features

* add proofs to platform responses ([#96](https://github.com/dashevo/dapi-grpc/issues/96))



# [0.16.0](https://github.com/dashevo/dapi-grpc/compare/v0.15.0...v0.16.0) (2020-10-26)


### Bug Fixes

* protobuf converts empty Buffer to undefined ([#94](https://github.com/dashevo/dapi-grpc/issues/94))


### Features

* add `getIdentitiesByPublicKeyHashes` and `getIdentityIdsByPublicKeyHashes` to platform service ([#89](https://github.com/dashevo/dapi-grpc/issues/89), [#92](https://github.com/dashevo/dapi-grpc/issues/92))
* use bytes for identifiers ([#91](https://github.com/dashevo/dapi-grpc/issues/91))


### BREAKING CHANGES

* `getIdentityIdByFirstPublicKey` and `getIdentityByFirstPublicKey` removed
* `GetDataContractRequest`, `GetDocumentsRequest`, `GetIdentityRequest` now accepts bytes



# [0.15.0](https://github.com/dashevo/dapi-grpc/compare/v0.14.0...v0.15.0) (2020-09-04)


### Features

* build version specific clients ([#85](https://github.com/dashevo/dapi-grpc/issues/86), [#86](https://github.com/dashevo/dapi-grpc/issues/86))
* combine `Core` and `TxFilterStream` services ([#84]((https://github.com/dashevo/dapi-grpc/issues/84)))
* update gRPC-Web to 1.2.0 version ([#83](https://github.com/dashevo/dapi-grpc/issues/83))


### BREAKING CHANGES

* paths to generated clients are changed
* `TxFilterStream` is removed. `subscribeToTransactionsWithProofs` included in Core service.



# [0.14.0](https://github.com/dashevo/dapi-grpc/compare/v0.13.0...v0.14.0) (2020-07-22)


### Features

* allow passing of options to calls in NodeJS clients ([#74](https://github.com/dashevo/dapi-grpc/issues/74))
* strip URL passed on to client and leave only ip/host:port pair ([#75](https://github.com/dashevo/dapi-grpc/issues/75))


### Refactoring

* refactor: remove java artifacts ([#78](https://github.com/dashevo/dapi-grpc/issues/78))


### Tests

* update Mocha config ([#77](https://github.com/dashevo/dapi-grpc/issues/77))



# [0.13.0](https://github.com/dashevo/dapi-grpc/compare/v0.12.1...v0.13.0) (2020-06-08)


### Features

* get identity by public key endpoints ([#71](https://github.com/dashevo/dapi-grpc/issues/71))
* add python to the list of clients generated ([#60](https://github.com/dashevo/dapi-grpc/issues/60))
* use protocol version interceptor in JS clients ([#63](https://github.com/dashevo/dapi-grpc/issues/63), [#68](https://github.com/dashevo/dapi-grpc/issues/68))



## [0.12.1](https://github.com/dashevo/dapi-grpc/compare/v0.12.0...v0.12.1) (2020-02-13)


### Bug Fixes

* namespacing of the `platform` service in the build ([#57](https://github.com/dashevo/dapi-grpc/issues/57)) ([2b22219](https://github.com/dashevo/dapi-grpc/commit/2b22219d319588413058f11e800a9603c0ee7a0c))



# [0.12.0](https://github.com/dashevo/dapi-grpc/compare/v0.11.0...v0.12.0) (2020-01-27)


### Bug Fixes

* core services ([1fde938](https://github.com/dashevo/dapi-grpc/commit/1fde938b2c48c9f79555203af1c615ff82b83ac5))
* platform bugs ([210cdd7](https://github.com/dashevo/dapi-grpc/commit/210cdd7709c009c0303d50c98089f22f8b96ebd8))


### Features

* add more methods to Core service ([41f3ad0](https://github.com/dashevo/dapi-grpc/commit/41f3ad0ad6aee3acf4b1760949cde36d8df7d6f2))
* fetchIdentity endpoint ([75d32d8](https://github.com/dashevo/dapi-grpc/commit/75d32d883be4d7a113fe34f1d008e1d9bcc3c7e1))
* introduce Platform service ([c88b891](https://github.com/dashevo/dapi-grpc/commit/c88b891ecfac8987cd76c773b2f783ad7a155540))


