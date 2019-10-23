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

@class ChainLockSignatureMessages;
@class RawBlockHeaders;

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

#pragma mark - LastUserStateTransitionHashRequest

typedef GPB_ENUM(LastUserStateTransitionHashRequest_FieldNumber) {
  LastUserStateTransitionHashRequest_FieldNumber_UserId = 1,
};

@interface LastUserStateTransitionHashRequest : GPBMessage

@property(nonatomic, readwrite, copy, null_resettable) NSData *userId;

@end

#pragma mark - LastUserStateTransitionHashResponse

typedef GPB_ENUM(LastUserStateTransitionHashResponse_FieldNumber) {
  LastUserStateTransitionHashResponse_FieldNumber_StateTransitionHash = 1,
};

@interface LastUserStateTransitionHashResponse : GPBMessage

@property(nonatomic, readwrite, copy, null_resettable) NSData *stateTransitionHash;

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
  BlockHeadersWithChainLocksResponse_FieldNumber_RawBlockHeaders = 1,
  BlockHeadersWithChainLocksResponse_FieldNumber_ChainLockSignatureMessages = 2,
};

typedef GPB_ENUM(BlockHeadersWithChainLocksResponse_Responses_OneOfCase) {
  BlockHeadersWithChainLocksResponse_Responses_OneOfCase_GPBUnsetOneOfCase = 0,
  BlockHeadersWithChainLocksResponse_Responses_OneOfCase_RawBlockHeaders = 1,
  BlockHeadersWithChainLocksResponse_Responses_OneOfCase_ChainLockSignatureMessages = 2,
};

@interface BlockHeadersWithChainLocksResponse : GPBMessage

@property(nonatomic, readonly) BlockHeadersWithChainLocksResponse_Responses_OneOfCase responsesOneOfCase;

@property(nonatomic, readwrite, strong, null_resettable) RawBlockHeaders *rawBlockHeaders;

@property(nonatomic, readwrite, strong, null_resettable) ChainLockSignatureMessages *chainLockSignatureMessages;

@end

/**
 * Clears whatever value was set for the oneof 'responses'.
 **/
void BlockHeadersWithChainLocksResponse_ClearResponsesOneOfCase(BlockHeadersWithChainLocksResponse *message);

#pragma mark - RawBlockHeaders

typedef GPB_ENUM(RawBlockHeaders_FieldNumber) {
  RawBlockHeaders_FieldNumber_HeadersArray = 1,
};

@interface RawBlockHeaders : GPBMessage

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

#pragma mark - StateTransition

typedef GPB_ENUM(StateTransition_FieldNumber) {
  StateTransition_FieldNumber_StateTransition = 1,
};

@interface StateTransition : GPBMessage

@property(nonatomic, readwrite, copy, null_resettable) NSData *stateTransition;

@end

#pragma mark - UpdateStateTransitionResponse

@interface UpdateStateTransitionResponse : GPBMessage

@end

NS_ASSUME_NONNULL_END

CF_EXTERN_C_END

#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)
