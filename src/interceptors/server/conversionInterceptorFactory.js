/**
 * Server-side JSON -> protobuf -> JSON handler wrapper (factory)
 *
 * @param {jsonToProtobuf} jsonToProtobuf
 * @param {protobufToJson} protobufToJson
 * @param {function(grpc.Call, function(Error|null, jspb.Message|null))} rpcMethod
 *
 * @returns {wrappedMethodHandler}
 */
function conversionInterceptorFactory(jsonToProtobuf, protobufToJson, rpcMethod) {
  /**
   * Server-side JSON -> protobuf -> JSON handler wrapper
   *
   * @typedef wrappedMethodHandler
   *
   * @param {grpc.Call} call
   * @param {function(Error|null, jspb.Message|null)} callback
   *
   * @returns {*}
   */
  function methodHandler(call, callback = undefined) {
    if (call.request) {
      // eslint-disable-next-line no-param-reassign
      call.request = jsonToProtobuf(call.request);
    }

    // eslint-disable-next-line no-param-reassign
    call.write = (message, flags, writeCallback) => {
      let convertedMessage = null;
      if (message) {
        convertedMessage = protobufToJson(message);
      }
      return call.write(convertedMessage, flags, writeCallback);
    };

    let interceptedCallback;
    if (callback) {
      interceptedCallback = (err, message) => {
        let convertedMessage = null;
        if (message) {
          convertedMessage = protobufToJson(message);
        }
        callback(err, convertedMessage);
      };
    }

    return rpcMethod(call, interceptedCallback);
  }

  return methodHandler;
}

module.exports = conversionInterceptorFactory;
