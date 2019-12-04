#import "Core.pbobjc.h"

#import <ProtoRPC/ProtoService.h>
#import <ProtoRPC/ProtoRPC.h>
#import <RxLibrary/GRXWriteable.h>
#import <RxLibrary/GRXWriter.h>



NS_ASSUME_NONNULL_BEGIN

@protocol Core <NSObject>

#pragma mark sendTransaction(SendTransactionRequest) returns (SendTransactionResponse)

- (void)sendTransactionWithRequest:(SendTransactionRequest *)request handler:(void(^)(SendTransactionResponse *_Nullable response, NSError *_Nullable error))handler;

- (GRPCProtoCall *)RPCTosendTransactionWithRequest:(SendTransactionRequest *)request handler:(void(^)(SendTransactionResponse *_Nullable response, NSError *_Nullable error))handler;


#pragma mark getBestBlockHeight(GetBestBlockHeightRequest) returns (GetBestBlockHeightResponse)

- (void)getBestBlockHeightWithRequest:(GetBestBlockHeightRequest *)request handler:(void(^)(GetBestBlockHeightResponse *_Nullable response, NSError *_Nullable error))handler;

- (GRPCProtoCall *)RPCTogetBestBlockHeightWithRequest:(GetBestBlockHeightRequest *)request handler:(void(^)(GetBestBlockHeightResponse *_Nullable response, NSError *_Nullable error))handler;


#pragma mark getTransaction(GetTransactionRequest) returns (GetTransactionResponse)

- (void)getTransactionWithRequest:(GetTransactionRequest *)request handler:(void(^)(GetTransactionResponse *_Nullable response, NSError *_Nullable error))handler;

- (GRPCProtoCall *)RPCTogetTransactionWithRequest:(GetTransactionRequest *)request handler:(void(^)(GetTransactionResponse *_Nullable response, NSError *_Nullable error))handler;


@end

/**
 * Basic service implementation, over gRPC, that only does
 * marshalling and parsing.
 */
@interface Core : GRPCProtoService<Core>
- (instancetype)initWithHost:(NSString *)host NS_DESIGNATED_INITIALIZER;
+ (instancetype)serviceWithHost:(NSString *)host;
@end

NS_ASSUME_NONNULL_END
