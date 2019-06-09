// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: core.proto

// This CPP symbol can be defined to use imports that match up to the framework
// imports needed when using CocoaPods.
#if !defined(GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS)
 #define GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS 0
#endif

#if GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS
 #import <Protobuf/GPBProtocolBuffers_RuntimeSupport.h>
#else
 #import "GPBProtocolBuffers_RuntimeSupport.h"
#endif

 #import "Core.pbobjc.h"
// @@protoc_insertion_point(imports)

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#pragma clang diagnostic ignored "-Wdirect-ivar-access"

#pragma mark - CoreRoot

@implementation CoreRoot

// No extensions in the file and no imports, so no need to generate
// +extensionRegistry.

@end

#pragma mark - CoreRoot_FileDescriptor

static GPBFileDescriptor *CoreRoot_FileDescriptor(void) {
  // This is called by +initialize so there is no need to worry
  // about thread safety of the singleton.
  static GPBFileDescriptor *descriptor = NULL;
  if (!descriptor) {
    GPB_DEBUG_CHECK_RUNTIME_VERSIONS();
    descriptor = [[GPBFileDescriptor alloc] initWithPackage:@"org.dash.platform.dapi"
                                                     syntax:GPBFileSyntaxProto3];
  }
  return descriptor;
}

#pragma mark - LastUserStateTransitionHashRequest

@implementation LastUserStateTransitionHashRequest

@dynamic userId;

typedef struct LastUserStateTransitionHashRequest__storage_ {
  uint32_t _has_storage_[1];
  NSData *userId;
} LastUserStateTransitionHashRequest__storage_;

// This method is threadsafe because it is initially called
// in +initialize for each subclass.
+ (GPBDescriptor *)descriptor {
  static GPBDescriptor *descriptor = nil;
  if (!descriptor) {
    static GPBMessageFieldDescription fields[] = {
      {
        .name = "userId",
        .dataTypeSpecific.className = NULL,
        .number = LastUserStateTransitionHashRequest_FieldNumber_UserId,
        .hasIndex = 0,
        .offset = (uint32_t)offsetof(LastUserStateTransitionHashRequest__storage_, userId),
        .flags = GPBFieldOptional,
        .dataType = GPBDataTypeBytes,
      },
    };
    GPBDescriptor *localDescriptor =
        [GPBDescriptor allocDescriptorForClass:[LastUserStateTransitionHashRequest class]
                                     rootClass:[CoreRoot class]
                                          file:CoreRoot_FileDescriptor()
                                        fields:fields
                                    fieldCount:(uint32_t)(sizeof(fields) / sizeof(GPBMessageFieldDescription))
                                   storageSize:sizeof(LastUserStateTransitionHashRequest__storage_)
                                         flags:GPBDescriptorInitializationFlag_None];
    NSAssert(descriptor == nil, @"Startup recursed!");
    descriptor = localDescriptor;
  }
  return descriptor;
}

@end

#pragma mark - LastUserStateTransitionHashResponse

@implementation LastUserStateTransitionHashResponse

@dynamic responsesOneOfCase;
@dynamic lastStateTransitionHash;
@dynamic regTxId;

typedef struct LastUserStateTransitionHashResponse__storage_ {
  uint32_t _has_storage_[2];
  NSData *lastStateTransitionHash;
  NSData *regTxId;
} LastUserStateTransitionHashResponse__storage_;

// This method is threadsafe because it is initially called
// in +initialize for each subclass.
+ (GPBDescriptor *)descriptor {
  static GPBDescriptor *descriptor = nil;
  if (!descriptor) {
    static GPBMessageFieldDescription fields[] = {
      {
        .name = "lastStateTransitionHash",
        .dataTypeSpecific.className = NULL,
        .number = LastUserStateTransitionHashResponse_FieldNumber_LastStateTransitionHash,
        .hasIndex = -1,
        .offset = (uint32_t)offsetof(LastUserStateTransitionHashResponse__storage_, lastStateTransitionHash),
        .flags = GPBFieldOptional,
        .dataType = GPBDataTypeBytes,
      },
      {
        .name = "regTxId",
        .dataTypeSpecific.className = NULL,
        .number = LastUserStateTransitionHashResponse_FieldNumber_RegTxId,
        .hasIndex = -1,
        .offset = (uint32_t)offsetof(LastUserStateTransitionHashResponse__storage_, regTxId),
        .flags = GPBFieldOptional,
        .dataType = GPBDataTypeBytes,
      },
    };
    GPBDescriptor *localDescriptor =
        [GPBDescriptor allocDescriptorForClass:[LastUserStateTransitionHashResponse class]
                                     rootClass:[CoreRoot class]
                                          file:CoreRoot_FileDescriptor()
                                        fields:fields
                                    fieldCount:(uint32_t)(sizeof(fields) / sizeof(GPBMessageFieldDescription))
                                   storageSize:sizeof(LastUserStateTransitionHashResponse__storage_)
                                         flags:GPBDescriptorInitializationFlag_None];
    static const char *oneofs[] = {
      "responses",
    };
    [localDescriptor setupOneofs:oneofs
                           count:(uint32_t)(sizeof(oneofs) / sizeof(char*))
                   firstHasIndex:-1];
    NSAssert(descriptor == nil, @"Startup recursed!");
    descriptor = localDescriptor;
  }
  return descriptor;
}

@end

void LastUserStateTransitionHashResponse_ClearResponsesOneOfCase(LastUserStateTransitionHashResponse *message) {
  GPBDescriptor *descriptor = [message descriptor];
  GPBOneofDescriptor *oneof = [descriptor.oneofs objectAtIndex:0];
  GPBMaybeClearOneof(message, oneof, -1, 0);
}
#pragma mark - BlockHeadersWithChainLocksRequest

@implementation BlockHeadersWithChainLocksRequest

@dynamic fromBlockOneOfCase;
@dynamic fromBlockHash;
@dynamic fromBlockHeight;
@dynamic count;

typedef struct BlockHeadersWithChainLocksRequest__storage_ {
  uint32_t _has_storage_[2];
  uint32_t fromBlockHeight;
  uint32_t count;
  NSData *fromBlockHash;
} BlockHeadersWithChainLocksRequest__storage_;

// This method is threadsafe because it is initially called
// in +initialize for each subclass.
+ (GPBDescriptor *)descriptor {
  static GPBDescriptor *descriptor = nil;
  if (!descriptor) {
    static GPBMessageFieldDescription fields[] = {
      {
        .name = "fromBlockHash",
        .dataTypeSpecific.className = NULL,
        .number = BlockHeadersWithChainLocksRequest_FieldNumber_FromBlockHash,
        .hasIndex = -1,
        .offset = (uint32_t)offsetof(BlockHeadersWithChainLocksRequest__storage_, fromBlockHash),
        .flags = (GPBFieldFlags)(GPBFieldOptional | GPBFieldTextFormatNameCustom),
        .dataType = GPBDataTypeBytes,
      },
      {
        .name = "fromBlockHeight",
        .dataTypeSpecific.className = NULL,
        .number = BlockHeadersWithChainLocksRequest_FieldNumber_FromBlockHeight,
        .hasIndex = -1,
        .offset = (uint32_t)offsetof(BlockHeadersWithChainLocksRequest__storage_, fromBlockHeight),
        .flags = (GPBFieldFlags)(GPBFieldOptional | GPBFieldTextFormatNameCustom),
        .dataType = GPBDataTypeUInt32,
      },
      {
        .name = "count",
        .dataTypeSpecific.className = NULL,
        .number = BlockHeadersWithChainLocksRequest_FieldNumber_Count,
        .hasIndex = 0,
        .offset = (uint32_t)offsetof(BlockHeadersWithChainLocksRequest__storage_, count),
        .flags = GPBFieldOptional,
        .dataType = GPBDataTypeUInt32,
      },
    };
    GPBDescriptor *localDescriptor =
        [GPBDescriptor allocDescriptorForClass:[BlockHeadersWithChainLocksRequest class]
                                     rootClass:[CoreRoot class]
                                          file:CoreRoot_FileDescriptor()
                                        fields:fields
                                    fieldCount:(uint32_t)(sizeof(fields) / sizeof(GPBMessageFieldDescription))
                                   storageSize:sizeof(BlockHeadersWithChainLocksRequest__storage_)
                                         flags:GPBDescriptorInitializationFlag_None];
    static const char *oneofs[] = {
      "fromBlock",
    };
    [localDescriptor setupOneofs:oneofs
                           count:(uint32_t)(sizeof(oneofs) / sizeof(char*))
                   firstHasIndex:-1];
#if !GPBOBJC_SKIP_MESSAGE_TEXTFORMAT_EXTRAS
    static const char *extraTextFormatInfo =
        "\002\001\r\000\002\017\000";
    [localDescriptor setupExtraTextInfo:extraTextFormatInfo];
#endif  // !GPBOBJC_SKIP_MESSAGE_TEXTFORMAT_EXTRAS
    NSAssert(descriptor == nil, @"Startup recursed!");
    descriptor = localDescriptor;
  }
  return descriptor;
}

@end

void BlockHeadersWithChainLocksRequest_ClearFromBlockOneOfCase(BlockHeadersWithChainLocksRequest *message) {
  GPBDescriptor *descriptor = [message descriptor];
  GPBOneofDescriptor *oneof = [descriptor.oneofs objectAtIndex:0];
  GPBMaybeClearOneof(message, oneof, -1, 0);
}
#pragma mark - BlockHeadersWithChainLocksResponse

@implementation BlockHeadersWithChainLocksResponse

@dynamic responsesOneOfCase;
@dynamic rawBlockHeaders;
@dynamic chainLockSignatureMessages;

typedef struct BlockHeadersWithChainLocksResponse__storage_ {
  uint32_t _has_storage_[2];
  RawBlockHeaders *rawBlockHeaders;
  ChainLockSignatureMessages *chainLockSignatureMessages;
} BlockHeadersWithChainLocksResponse__storage_;

// This method is threadsafe because it is initially called
// in +initialize for each subclass.
+ (GPBDescriptor *)descriptor {
  static GPBDescriptor *descriptor = nil;
  if (!descriptor) {
    static GPBMessageFieldDescription fields[] = {
      {
        .name = "rawBlockHeaders",
        .dataTypeSpecific.className = GPBStringifySymbol(RawBlockHeaders),
        .number = BlockHeadersWithChainLocksResponse_FieldNumber_RawBlockHeaders,
        .hasIndex = -1,
        .offset = (uint32_t)offsetof(BlockHeadersWithChainLocksResponse__storage_, rawBlockHeaders),
        .flags = GPBFieldOptional,
        .dataType = GPBDataTypeMessage,
      },
      {
        .name = "chainLockSignatureMessages",
        .dataTypeSpecific.className = GPBStringifySymbol(ChainLockSignatureMessages),
        .number = BlockHeadersWithChainLocksResponse_FieldNumber_ChainLockSignatureMessages,
        .hasIndex = -1,
        .offset = (uint32_t)offsetof(BlockHeadersWithChainLocksResponse__storage_, chainLockSignatureMessages),
        .flags = GPBFieldOptional,
        .dataType = GPBDataTypeMessage,
      },
    };
    GPBDescriptor *localDescriptor =
        [GPBDescriptor allocDescriptorForClass:[BlockHeadersWithChainLocksResponse class]
                                     rootClass:[CoreRoot class]
                                          file:CoreRoot_FileDescriptor()
                                        fields:fields
                                    fieldCount:(uint32_t)(sizeof(fields) / sizeof(GPBMessageFieldDescription))
                                   storageSize:sizeof(BlockHeadersWithChainLocksResponse__storage_)
                                         flags:GPBDescriptorInitializationFlag_None];
    static const char *oneofs[] = {
      "responses",
    };
    [localDescriptor setupOneofs:oneofs
                           count:(uint32_t)(sizeof(oneofs) / sizeof(char*))
                   firstHasIndex:-1];
    NSAssert(descriptor == nil, @"Startup recursed!");
    descriptor = localDescriptor;
  }
  return descriptor;
}

@end

void BlockHeadersWithChainLocksResponse_ClearResponsesOneOfCase(BlockHeadersWithChainLocksResponse *message) {
  GPBDescriptor *descriptor = [message descriptor];
  GPBOneofDescriptor *oneof = [descriptor.oneofs objectAtIndex:0];
  GPBMaybeClearOneof(message, oneof, -1, 0);
}
#pragma mark - RawBlockHeaders

@implementation RawBlockHeaders

@dynamic headersArray, headersArray_Count;

typedef struct RawBlockHeaders__storage_ {
  uint32_t _has_storage_[1];
  NSMutableArray *headersArray;
} RawBlockHeaders__storage_;

// This method is threadsafe because it is initially called
// in +initialize for each subclass.
+ (GPBDescriptor *)descriptor {
  static GPBDescriptor *descriptor = nil;
  if (!descriptor) {
    static GPBMessageFieldDescription fields[] = {
      {
        .name = "headersArray",
        .dataTypeSpecific.className = NULL,
        .number = RawBlockHeaders_FieldNumber_HeadersArray,
        .hasIndex = GPBNoHasBit,
        .offset = (uint32_t)offsetof(RawBlockHeaders__storage_, headersArray),
        .flags = GPBFieldRepeated,
        .dataType = GPBDataTypeBytes,
      },
    };
    GPBDescriptor *localDescriptor =
        [GPBDescriptor allocDescriptorForClass:[RawBlockHeaders class]
                                     rootClass:[CoreRoot class]
                                          file:CoreRoot_FileDescriptor()
                                        fields:fields
                                    fieldCount:(uint32_t)(sizeof(fields) / sizeof(GPBMessageFieldDescription))
                                   storageSize:sizeof(RawBlockHeaders__storage_)
                                         flags:GPBDescriptorInitializationFlag_None];
    NSAssert(descriptor == nil, @"Startup recursed!");
    descriptor = localDescriptor;
  }
  return descriptor;
}

@end

#pragma mark - ChainLockSignatureMessages

@implementation ChainLockSignatureMessages

@dynamic messagesArray, messagesArray_Count;

typedef struct ChainLockSignatureMessages__storage_ {
  uint32_t _has_storage_[1];
  NSMutableArray *messagesArray;
} ChainLockSignatureMessages__storage_;

// This method is threadsafe because it is initially called
// in +initialize for each subclass.
+ (GPBDescriptor *)descriptor {
  static GPBDescriptor *descriptor = nil;
  if (!descriptor) {
    static GPBMessageFieldDescription fields[] = {
      {
        .name = "messagesArray",
        .dataTypeSpecific.className = NULL,
        .number = ChainLockSignatureMessages_FieldNumber_MessagesArray,
        .hasIndex = GPBNoHasBit,
        .offset = (uint32_t)offsetof(ChainLockSignatureMessages__storage_, messagesArray),
        .flags = GPBFieldRepeated,
        .dataType = GPBDataTypeBytes,
      },
    };
    GPBDescriptor *localDescriptor =
        [GPBDescriptor allocDescriptorForClass:[ChainLockSignatureMessages class]
                                     rootClass:[CoreRoot class]
                                          file:CoreRoot_FileDescriptor()
                                        fields:fields
                                    fieldCount:(uint32_t)(sizeof(fields) / sizeof(GPBMessageFieldDescription))
                                   storageSize:sizeof(ChainLockSignatureMessages__storage_)
                                         flags:GPBDescriptorInitializationFlag_None];
    NSAssert(descriptor == nil, @"Startup recursed!");
    descriptor = localDescriptor;
  }
  return descriptor;
}

@end


#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)
