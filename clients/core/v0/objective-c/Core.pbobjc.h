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
@class BloomFilter;
@class ChainLockSignatureMessages;
@class GetStatusResponse_Chain;
@class GetStatusResponse_Masternode;
@class GetStatusResponse_Network;
@class GetStatusResponse_Network_Fee;
@class GetStatusResponse_Time;
@class GetStatusResponse_Version;
@class InstantSendLockMessages;
@class RawTransactions;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Enum GetStatusResponse_Status

typedef GPB_ENUM(GetStatusResponse_Status) {
  /**
   * Value used if any message's field encounters a value that is not defined
   * by this enum. The message will also have C functions to get/set the rawValue
   * of the field.
   **/
  GetStatusResponse_Status_GPBUnrecognizedEnumeratorValue = kGPBUnrecognizedEnumeratorValue,
  GetStatusResponse_Status_NotStarted = 0,
  GetStatusResponse_Status_Syncing = 1,
  GetStatusResponse_Status_Ready = 2,
  GetStatusResponse_Status_Error = 3,
};

GPBEnumDescriptor *GetStatusResponse_Status_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL GetStatusResponse_Status_IsValidValue(int32_t value);

#pragma mark - Enum GetStatusResponse_Masternode_State

typedef GPB_ENUM(GetStatusResponse_Masternode_State) {
  /**
   * Value used if any message's field encounters a value that is not defined
   * by this enum. The message will also have C functions to get/set the rawValue
   * of the field.
   **/
  GetStatusResponse_Masternode_State_GPBUnrecognizedEnumeratorValue = kGPBUnrecognizedEnumeratorValue,
  GetStatusResponse_Masternode_State_Unknown = 0,
  GetStatusResponse_Masternode_State_WaitingForProtx = 1,
  GetStatusResponse_Masternode_State_PoseBanned = 2,
  GetStatusResponse_Masternode_State_Removed = 3,
  GetStatusResponse_Masternode_State_OperatorKeyChanged = 4,
  GetStatusResponse_Masternode_State_ProtxIpChanged = 5,
  GetStatusResponse_Masternode_State_Ready = 6,
  GetStatusResponse_Masternode_State_Error = 7,
};

GPBEnumDescriptor *GetStatusResponse_Masternode_State_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL GetStatusResponse_Masternode_State_IsValidValue(int32_t value);

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
  GetStatusResponse_FieldNumber_Version = 1,
  GetStatusResponse_FieldNumber_Time = 2,
  GetStatusResponse_FieldNumber_Status = 3,
  GetStatusResponse_FieldNumber_SyncProgress = 4,
  GetStatusResponse_FieldNumber_Chain = 5,
  GetStatusResponse_FieldNumber_Masternode = 6,
  GetStatusResponse_FieldNumber_Network = 7,
};

@interface GetStatusResponse : GPBMessage

@property(nonatomic, readwrite, strong, null_resettable) GetStatusResponse_Version *version;
/** Test to see if @c version has been set. */
@property(nonatomic, readwrite) BOOL hasVersion;

@property(nonatomic, readwrite, strong, null_resettable) GetStatusResponse_Time *time;
/** Test to see if @c time has been set. */
@property(nonatomic, readwrite) BOOL hasTime;

@property(nonatomic, readwrite) GetStatusResponse_Status status;

@property(nonatomic, readwrite) double syncProgress;

@property(nonatomic, readwrite, strong, null_resettable) GetStatusResponse_Chain *chain;
/** Test to see if @c chain has been set. */
@property(nonatomic, readwrite) BOOL hasChain;

@property(nonatomic, readwrite, strong, null_resettable) GetStatusResponse_Masternode *masternode;
/** Test to see if @c masternode has been set. */
@property(nonatomic, readwrite) BOOL hasMasternode;

@property(nonatomic, readwrite, strong, null_resettable) GetStatusResponse_Network *network;
/** Test to see if @c network has been set. */
@property(nonatomic, readwrite) BOOL hasNetwork;

@end

/**
 * Fetches the raw value of a @c GetStatusResponse's @c status property, even
 * if the value was not defined by the enum at the time the code was generated.
 **/
int32_t GetStatusResponse_Status_RawValue(GetStatusResponse *message);
/**
 * Sets the raw value of an @c GetStatusResponse's @c status property, allowing
 * it to be set to a value that was not defined by the enum at the time the code
 * was generated.
 **/
void SetGetStatusResponse_Status_RawValue(GetStatusResponse *message, int32_t value);

#pragma mark - GetStatusResponse_Version

typedef GPB_ENUM(GetStatusResponse_Version_FieldNumber) {
  GetStatusResponse_Version_FieldNumber_Protocol = 1,
  GetStatusResponse_Version_FieldNumber_Software = 2,
  GetStatusResponse_Version_FieldNumber_Agent = 3,
};

@interface GetStatusResponse_Version : GPBMessage

@property(nonatomic, readwrite) uint32_t protocol;

@property(nonatomic, readwrite) uint32_t software;

@property(nonatomic, readwrite, copy, null_resettable) NSString *agent;

@end

#pragma mark - GetStatusResponse_Time

typedef GPB_ENUM(GetStatusResponse_Time_FieldNumber) {
  GetStatusResponse_Time_FieldNumber_Now = 1,
  GetStatusResponse_Time_FieldNumber_Offset = 2,
  GetStatusResponse_Time_FieldNumber_Median = 3,
};

@interface GetStatusResponse_Time : GPBMessage

@property(nonatomic, readwrite) uint32_t now;

@property(nonatomic, readwrite) int32_t offset;

@property(nonatomic, readwrite) uint32_t median;

@end

#pragma mark - GetStatusResponse_Chain

typedef GPB_ENUM(GetStatusResponse_Chain_FieldNumber) {
  GetStatusResponse_Chain_FieldNumber_Name = 1,
  GetStatusResponse_Chain_FieldNumber_HeadersCount = 2,
  GetStatusResponse_Chain_FieldNumber_BlocksCount = 3,
  GetStatusResponse_Chain_FieldNumber_BestBlockHash = 4,
  GetStatusResponse_Chain_FieldNumber_Difficulty = 5,
  GetStatusResponse_Chain_FieldNumber_ChainWork = 6,
  GetStatusResponse_Chain_FieldNumber_IsSynced = 7,
  GetStatusResponse_Chain_FieldNumber_SyncProgress = 8,
};

@interface GetStatusResponse_Chain : GPBMessage

@property(nonatomic, readwrite, copy, null_resettable) NSString *name;

@property(nonatomic, readwrite) uint32_t headersCount;

@property(nonatomic, readwrite) uint32_t blocksCount;

@property(nonatomic, readwrite, copy, null_resettable) NSData *bestBlockHash;

@property(nonatomic, readwrite) double difficulty;

@property(nonatomic, readwrite, copy, null_resettable) NSData *chainWork;

@property(nonatomic, readwrite) BOOL isSynced;

@property(nonatomic, readwrite) double syncProgress;

@end

#pragma mark - GetStatusResponse_Masternode

typedef GPB_ENUM(GetStatusResponse_Masternode_FieldNumber) {
  GetStatusResponse_Masternode_FieldNumber_State = 1,
  GetStatusResponse_Masternode_FieldNumber_ProTxHash = 2,
  GetStatusResponse_Masternode_FieldNumber_PosePenalty = 3,
  GetStatusResponse_Masternode_FieldNumber_IsSynced = 4,
  GetStatusResponse_Masternode_FieldNumber_SyncProgress = 5,
};

@interface GetStatusResponse_Masternode : GPBMessage

@property(nonatomic, readwrite) GetStatusResponse_Status state;

@property(nonatomic, readwrite, copy, null_resettable) NSData *proTxHash;

@property(nonatomic, readwrite) uint32_t posePenalty;

@property(nonatomic, readwrite) BOOL isSynced;

@property(nonatomic, readwrite) double syncProgress;

@end

/**
 * Fetches the raw value of a @c GetStatusResponse_Masternode's @c state property, even
 * if the value was not defined by the enum at the time the code was generated.
 **/
int32_t GetStatusResponse_Masternode_State_RawValue(GetStatusResponse_Masternode *message);
/**
 * Sets the raw value of an @c GetStatusResponse_Masternode's @c state property, allowing
 * it to be set to a value that was not defined by the enum at the time the code
 * was generated.
 **/
void SetGetStatusResponse_Masternode_State_RawValue(GetStatusResponse_Masternode *message, int32_t value);

#pragma mark - GetStatusResponse_Network

typedef GPB_ENUM(GetStatusResponse_Network_FieldNumber) {
  GetStatusResponse_Network_FieldNumber_PeersCount = 1,
  GetStatusResponse_Network_FieldNumber_Fee = 2,
};

@interface GetStatusResponse_Network : GPBMessage

@property(nonatomic, readwrite) uint32_t peersCount;

@property(nonatomic, readwrite, strong, null_resettable) GetStatusResponse_Network_Fee *fee;
/** Test to see if @c fee has been set. */
@property(nonatomic, readwrite) BOOL hasFee;

@end

#pragma mark - GetStatusResponse_Network_Fee

typedef GPB_ENUM(GetStatusResponse_Network_Fee_FieldNumber) {
  GetStatusResponse_Network_Fee_FieldNumber_Relay = 1,
  GetStatusResponse_Network_Fee_FieldNumber_Incremental = 2,
};

@interface GetStatusResponse_Network_Fee : GPBMessage

@property(nonatomic, readwrite) double relay;

@property(nonatomic, readwrite) double incremental;

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

#pragma mark - BroadcastTransactionRequest

typedef GPB_ENUM(BroadcastTransactionRequest_FieldNumber) {
  BroadcastTransactionRequest_FieldNumber_Transaction = 1,
  BroadcastTransactionRequest_FieldNumber_AllowHighFees = 2,
  BroadcastTransactionRequest_FieldNumber_BypassLimits = 3,
};

@interface BroadcastTransactionRequest : GPBMessage

@property(nonatomic, readwrite, copy, null_resettable) NSData *transaction;

@property(nonatomic, readwrite) BOOL allowHighFees;

@property(nonatomic, readwrite) BOOL bypassLimits;

@end

#pragma mark - BroadcastTransactionResponse

typedef GPB_ENUM(BroadcastTransactionResponse_FieldNumber) {
  BroadcastTransactionResponse_FieldNumber_TransactionId = 1,
};

@interface BroadcastTransactionResponse : GPBMessage

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

typedef GPB_ENUM(GetEstimatedTransactionFeeRequest_FieldNumber) {
  GetEstimatedTransactionFeeRequest_FieldNumber_Blocks = 1,
};

@interface GetEstimatedTransactionFeeRequest : GPBMessage

@property(nonatomic, readwrite) uint32_t blocks;

@end

#pragma mark - GetEstimatedTransactionFeeResponse

typedef GPB_ENUM(GetEstimatedTransactionFeeResponse_FieldNumber) {
  GetEstimatedTransactionFeeResponse_FieldNumber_Fee = 1,
};

@interface GetEstimatedTransactionFeeResponse : GPBMessage

@property(nonatomic, readwrite) double fee;

@end

#pragma mark - TransactionsWithProofsRequest

typedef GPB_ENUM(TransactionsWithProofsRequest_FieldNumber) {
  TransactionsWithProofsRequest_FieldNumber_BloomFilter = 1,
  TransactionsWithProofsRequest_FieldNumber_FromBlockHash = 2,
  TransactionsWithProofsRequest_FieldNumber_FromBlockHeight = 3,
  TransactionsWithProofsRequest_FieldNumber_Count = 4,
  TransactionsWithProofsRequest_FieldNumber_SendTransactionHashes = 5,
};

typedef GPB_ENUM(TransactionsWithProofsRequest_FromBlock_OneOfCase) {
  TransactionsWithProofsRequest_FromBlock_OneOfCase_GPBUnsetOneOfCase = 0,
  TransactionsWithProofsRequest_FromBlock_OneOfCase_FromBlockHash = 2,
  TransactionsWithProofsRequest_FromBlock_OneOfCase_FromBlockHeight = 3,
};

@interface TransactionsWithProofsRequest : GPBMessage

@property(nonatomic, readwrite, strong, null_resettable) BloomFilter *bloomFilter;
/** Test to see if @c bloomFilter has been set. */
@property(nonatomic, readwrite) BOOL hasBloomFilter;

@property(nonatomic, readonly) TransactionsWithProofsRequest_FromBlock_OneOfCase fromBlockOneOfCase;

@property(nonatomic, readwrite, copy, null_resettable) NSData *fromBlockHash;

@property(nonatomic, readwrite) uint32_t fromBlockHeight;

@property(nonatomic, readwrite) uint32_t count;

@property(nonatomic, readwrite) BOOL sendTransactionHashes;

@end

/**
 * Clears whatever value was set for the oneof 'fromBlock'.
 **/
void TransactionsWithProofsRequest_ClearFromBlockOneOfCase(TransactionsWithProofsRequest *message);

#pragma mark - BloomFilter

typedef GPB_ENUM(BloomFilter_FieldNumber) {
  BloomFilter_FieldNumber_VData = 1,
  BloomFilter_FieldNumber_NHashFuncs = 2,
  BloomFilter_FieldNumber_NTweak = 3,
  BloomFilter_FieldNumber_NFlags = 4,
};

@interface BloomFilter : GPBMessage

@property(nonatomic, readwrite, copy, null_resettable) NSData *vData;

@property(nonatomic, readwrite) uint32_t nHashFuncs;

@property(nonatomic, readwrite) uint32_t nTweak;

@property(nonatomic, readwrite) uint32_t nFlags;

@end

#pragma mark - TransactionsWithProofsResponse

typedef GPB_ENUM(TransactionsWithProofsResponse_FieldNumber) {
  TransactionsWithProofsResponse_FieldNumber_RawTransactions = 1,
  TransactionsWithProofsResponse_FieldNumber_InstantSendLockMessages = 2,
  TransactionsWithProofsResponse_FieldNumber_RawMerkleBlock = 3,
};

typedef GPB_ENUM(TransactionsWithProofsResponse_Responses_OneOfCase) {
  TransactionsWithProofsResponse_Responses_OneOfCase_GPBUnsetOneOfCase = 0,
  TransactionsWithProofsResponse_Responses_OneOfCase_RawTransactions = 1,
  TransactionsWithProofsResponse_Responses_OneOfCase_InstantSendLockMessages = 2,
  TransactionsWithProofsResponse_Responses_OneOfCase_RawMerkleBlock = 3,
};

@interface TransactionsWithProofsResponse : GPBMessage

@property(nonatomic, readonly) TransactionsWithProofsResponse_Responses_OneOfCase responsesOneOfCase;

@property(nonatomic, readwrite, strong, null_resettable) RawTransactions *rawTransactions;

@property(nonatomic, readwrite, strong, null_resettable) InstantSendLockMessages *instantSendLockMessages;

@property(nonatomic, readwrite, copy, null_resettable) NSData *rawMerkleBlock;

@end

/**
 * Clears whatever value was set for the oneof 'responses'.
 **/
void TransactionsWithProofsResponse_ClearResponsesOneOfCase(TransactionsWithProofsResponse *message);

#pragma mark - RawTransactions

typedef GPB_ENUM(RawTransactions_FieldNumber) {
  RawTransactions_FieldNumber_TransactionsArray = 1,
};

@interface RawTransactions : GPBMessage

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<NSData*> *transactionsArray;
/** The number of items in @c transactionsArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger transactionsArray_Count;

@end

#pragma mark - InstantSendLockMessages

typedef GPB_ENUM(InstantSendLockMessages_FieldNumber) {
  InstantSendLockMessages_FieldNumber_MessagesArray = 1,
};

@interface InstantSendLockMessages : GPBMessage

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<NSData*> *messagesArray;
/** The number of items in @c messagesArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger messagesArray_Count;

@end

NS_ASSUME_NONNULL_END

CF_EXTERN_C_END

#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)
