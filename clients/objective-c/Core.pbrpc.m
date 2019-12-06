#import "Core.pbrpc.h"

#import <ProtoRPC/ProtoRPC.h>
#import <RxLibrary/GRXWriter+Immediate.h>

@implementation Core

// Designated initializer
- (instancetype)initWithHost:(NSString *)host {
  return (self = [super initWithHost:host packageName:@"org.dash.platform.dapi.v0" serviceName:@"Core"]);
}

// Override superclass initializer to disallow different package and service names.
- (instancetype)initWithHost:(NSString *)host
                 packageName:(NSString *)packageName
                 serviceName:(NSString *)serviceName {
  return [self initWithHost:host];
}

+ (instancetype)serviceWithHost:(NSString *)host {
  return [[self alloc] initWithHost:host];
}


#pragma mark sendTransaction(SendTransactionRequest) returns (SendTransactionResponse)

- (void)sendTransactionWithRequest:(SendTransactionRequest *)request handler:(void(^)(SendTransactionResponse *_Nullable response, NSError *_Nullable error))handler{
  [[self RPCTosendTransactionWithRequest:request handler:handler] start];
}
// Returns a not-yet-started RPC object.
- (GRPCProtoCall *)RPCTosendTransactionWithRequest:(SendTransactionRequest *)request handler:(void(^)(SendTransactionResponse *_Nullable response, NSError *_Nullable error))handler{
  return [self RPCToMethod:@"sendTransaction"
            requestsWriter:[GRXWriter writerWithValue:request]
             responseClass:[SendTransactionResponse class]
        responsesWriteable:[GRXWriteable writeableWithSingleHandler:handler]];
}
#pragma mark getTransaction(GetTransactionRequest) returns (GetTransactionResponse)

- (void)getTransactionWithRequest:(GetTransactionRequest *)request handler:(void(^)(GetTransactionResponse *_Nullable response, NSError *_Nullable error))handler{
  [[self RPCTogetTransactionWithRequest:request handler:handler] start];
}
// Returns a not-yet-started RPC object.
- (GRPCProtoCall *)RPCTogetTransactionWithRequest:(GetTransactionRequest *)request handler:(void(^)(GetTransactionResponse *_Nullable response, NSError *_Nullable error))handler{
  return [self RPCToMethod:@"getTransaction"
            requestsWriter:[GRXWriter writerWithValue:request]
             responseClass:[GetTransactionResponse class]
        responsesWriteable:[GRXWriteable writeableWithSingleHandler:handler]];
}
#pragma mark getBestBlockHeight(GetBestBlockHeightRequest) returns (GetBestBlockHeightResponse)

- (void)getBestBlockHeightWithRequest:(GetBestBlockHeightRequest *)request handler:(void(^)(GetBestBlockHeightResponse *_Nullable response, NSError *_Nullable error))handler{
  [[self RPCTogetBestBlockHeightWithRequest:request handler:handler] start];
}
// Returns a not-yet-started RPC object.
- (GRPCProtoCall *)RPCTogetBestBlockHeightWithRequest:(GetBestBlockHeightRequest *)request handler:(void(^)(GetBestBlockHeightResponse *_Nullable response, NSError *_Nullable error))handler{
  return [self RPCToMethod:@"getBestBlockHeight"
            requestsWriter:[GRXWriter writerWithValue:request]
             responseClass:[GetBestBlockHeightResponse class]
        responsesWriteable:[GRXWriteable writeableWithSingleHandler:handler]];
}
@end
