// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: core.proto

// This CPP symbol can be defined to use imports that match up to the framework
// imports needed when using CocoaPods.
#if !defined(GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS)
 #define GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS 0
#endif

#if GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS
 #import <Protobuf/GPBProtocolBuffers.h>
#else
 #import "GPBProtocolBuffers.h"
#endif

#if GOOGLE_PROTOBUF_OBJC_VERSION < 30002
#error This file was generated by a newer version of protoc which is incompatible with your Protocol Buffer library sources.
#endif
#if 30002 < GOOGLE_PROTOBUF_OBJC_MIN_SUPPORTED_VERSION
#error This file was generated by an older version of protoc which is incompatible with your Protocol Buffer library sources.
#endif

// @@protoc_insertion_point(imports)

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

CF_EXTERN_C_BEGIN

@class BlockHeaders;
@class ChainLockSignatureMessages;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - CoreRoot

/**
 * Exposes the extension registry for this file.
 *
 * The base class provides:
 * @code
 *   + (GPBExtensionRegistry *)extensionRegistry;
 * @endcode
 * which is a @c GPBExtensionRegistry that includes all the extensions defined by
 * this file and all files that it depends on.
 **/
@interface CoreRoot : GPBRootObject
@end

#pragma mark - GetStatusRequest

@interface GetStatusRequest : GPBMessage

@end

#pragma mark - GetStatusResponse

typedef GPB_ENUM(GetStatusResponse_FieldNumber) {
  GetStatusResponse_FieldNumber_CoreVersion = 1,
  GetStatusResponse_FieldNumber_ProtocolVersion = 2,
  GetStatusResponse_FieldNumber_Blocks = 3,
  GetStatusResponse_FieldNumber_TimeOffset = 4,
  GetStatusResponse_FieldNumber_Connections = 5,
  GetStatusResponse_FieldNumber_Proxy = 6,
  GetStatusResponse_FieldNumber_Difficulty = 7,
  GetStatusResponse_FieldNumber_Testnet = 8,
  GetStatusResponse_FieldNumber_RelayFee = 9,
  GetStatusResponse_FieldNumber_Errors = 10,
  GetStatusResponse_FieldNumber_Network = 11,
};

@interface GetStatusResponse : GPBMessage

@property(nonatomic, readwrite) uint32_t coreVersion;

@property(nonatomic, readwrite) uint32_t protocolVersion;

@property(nonatomic, readwrite) uint32_t blocks;

@property(nonatomic, readwrite) uint32_t timeOffset;

@property(nonatomic, readwrite) uint32_t connections;

@property(nonatomic, readwrite, copy, null_resettable) NSString *proxy;

@property(nonatomic, readwrite) double difficulty;

@property(nonatomic, readwrite) BOOL testnet;

@property(nonatomic, readwrite) double relayFee;

@property(nonatomic, readwrite, copy, null_resettable) NSString *errors;

@property(nonatomic, readwrite, copy, null_resettable) NSString *network;

@end

#pragma mark - GetBlockRequest

typedef GPB_ENUM(GetBlockRequest_FieldNumber) {
  GetBlockRequest_FieldNumber_Height = 1,
  GetBlockRequest_FieldNumber_Hash_p = 2,
};

typedef GPB_ENUM(GetBlockRequest_Block_OneOfCase) {
  GetBlockRequest_Block_OneOfCase_GPBUnsetOneOfCase = 0,
  GetBlockRequest_Block_OneOfCase_Height = 1,
  GetBlockRequest_Block_OneOfCase_Hash_p = 2,
};

@interface GetBlockRequest : GPBMessage

@property(nonatomic, readonly) GetBlockRequest_Block_OneOfCase blockOneOfCase;

@property(nonatomic, readwrite) uint32_t height;

@property(nonatomic, readwrite, copy, null_resettable) NSString *hash_p;

@end

/**
 * Clears whatever value was set for the oneof 'block'.
 **/
void GetBlockRequest_ClearBlockOneOfCase(GetBlockRequest *message);

#pragma mark - GetBlockResponse

typedef GPB_ENUM(GetBlockResponse_FieldNumber) {
  GetBlockResponse_FieldNumber_Block = 1,
};

@interface GetBlockResponse : GPBMessage

@property(nonatomic, readwrite, copy, null_resettable) NSData *block;

@end

#pragma mark - SendTransactionRequest

typedef GPB_ENUM(SendTransactionRequest_FieldNumber) {
  SendTransactionRequest_FieldNumber_Transaction = 1,
  SendTransactionRequest_FieldNumber_AllowHighFees = 2,
  SendTransactionRequest_FieldNumber_BypassLimits = 3,
};

@interface SendTransactionRequest : GPBMessage

@property(nonatomic, readwrite, copy, null_resettable) NSData *transaction;

@property(nonatomic, readwrite) BOOL allowHighFees;

@property(nonatomic, readwrite) BOOL bypassLimits;

@end

#pragma mark - SendTransactionResponse

typedef GPB_ENUM(SendTransactionResponse_FieldNumber) {
  SendTransactionResponse_FieldNumber_TransactionId = 1,
};

@interface SendTransactionResponse : GPBMessage

@property(nonatomic, readwrite, copy, null_resettable) NSString *transactionId;

@end

#pragma mark - GetTransactionRequest

typedef GPB_ENUM(GetTransactionRequest_FieldNumber) {
  GetTransactionRequest_FieldNumber_Id_p = 1,
};

@interface GetTransactionRequest : GPBMessage

@property(nonatomic, readwrite, copy, null_resettable) NSString *id_p;

@end

#pragma mark - GetTransactionResponse

typedef GPB_ENUM(GetTransactionResponse_FieldNumber) {
  GetTransactionResponse_FieldNumber_Transaction = 1,
};

@interface GetTransactionResponse : GPBMessage

@property(nonatomic, readwrite, copy, null_resettable) NSData *transaction;

@end

#pragma mark - BlockHeadersWithChainLocksRequest

typedef GPB_ENUM(BlockHeadersWithChainLocksRequest_FieldNumber) {
  BlockHeadersWithChainLocksRequest_FieldNumber_FromBlockHash = 1,
  BlockHeadersWithChainLocksRequest_FieldNumber_FromBlockHeight = 2,
  BlockHeadersWithChainLocksRequest_FieldNumber_Count = 3,
};

typedef GPB_ENUM(BlockHeadersWithChainLocksRequest_FromBlock_OneOfCase) {
  BlockHeadersWithChainLocksRequest_FromBlock_OneOfCase_GPBUnsetOneOfCase = 0,
  BlockHeadersWithChainLocksRequest_FromBlock_OneOfCase_FromBlockHash = 1,
  BlockHeadersWithChainLocksRequest_FromBlock_OneOfCase_FromBlockHeight = 2,
};

@interface BlockHeadersWithChainLocksRequest : GPBMessage

@property(nonatomic, readonly) BlockHeadersWithChainLocksRequest_FromBlock_OneOfCase fromBlockOneOfCase;

@property(nonatomic, readwrite, copy, null_resettable) NSData *fromBlockHash;

@property(nonatomic, readwrite) uint32_t fromBlockHeight;

@property(nonatomic, readwrite) uint32_t count;

@end

/**
 * Clears whatever value was set for the oneof 'fromBlock'.
 **/
void BlockHeadersWithChainLocksRequest_ClearFromBlockOneOfCase(BlockHeadersWithChainLocksRequest *message);

#pragma mark - BlockHeadersWithChainLocksResponse

typedef GPB_ENUM(BlockHeadersWithChainLocksResponse_FieldNumber) {
  BlockHeadersWithChainLocksResponse_FieldNumber_BlockHeaders = 1,
  BlockHeadersWithChainLocksResponse_FieldNumber_ChainLockSignatureMessages = 2,
};

typedef GPB_ENUM(BlockHeadersWithChainLocksResponse_Responses_OneOfCase) {
  BlockHeadersWithChainLocksResponse_Responses_OneOfCase_GPBUnsetOneOfCase = 0,
  BlockHeadersWithChainLocksResponse_Responses_OneOfCase_BlockHeaders = 1,
  BlockHeadersWithChainLocksResponse_Responses_OneOfCase_ChainLockSignatureMessages = 2,
};

@interface BlockHeadersWithChainLocksResponse : GPBMessage

@property(nonatomic, readonly) BlockHeadersWithChainLocksResponse_Responses_OneOfCase responsesOneOfCase;

@property(nonatomic, readwrite, strong, null_resettable) BlockHeaders *blockHeaders;

@property(nonatomic, readwrite, strong, null_resettable) ChainLockSignatureMessages *chainLockSignatureMessages;

@end

/**
 * Clears whatever value was set for the oneof 'responses'.
 **/
void BlockHeadersWithChainLocksResponse_ClearResponsesOneOfCase(BlockHeadersWithChainLocksResponse *message);

#pragma mark - BlockHeaders

typedef GPB_ENUM(BlockHeaders_FieldNumber) {
  BlockHeaders_FieldNumber_HeadersArray = 1,
};

@interface BlockHeaders : GPBMessage

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<NSData*> *headersArray;
/** The number of items in @c headersArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger headersArray_Count;

@end

#pragma mark - ChainLockSignatureMessages

typedef GPB_ENUM(ChainLockSignatureMessages_FieldNumber) {
  ChainLockSignatureMessages_FieldNumber_MessagesArray = 1,
};

@interface ChainLockSignatureMessages : GPBMessage

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<NSData*> *messagesArray;
/** The number of items in @c messagesArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger messagesArray_Count;

@end

#pragma mark - GetEstimatedTransactionFeeRequest

@interface GetEstimatedTransactionFeeRequest : GPBMessage

@end

#pragma mark - GetEstimatedTransactionFeeResponse

typedef GPB_ENUM(GetEstimatedTransactionFeeResponse_FieldNumber) {
  GetEstimatedTransactionFeeResponse_FieldNumber_Fee = 1,
};

@interface GetEstimatedTransactionFeeResponse : GPBMessage

@property(nonatomic, readwrite) double fee;

@end

NS_ASSUME_NONNULL_END

CF_EXTERN_C_END

#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)
