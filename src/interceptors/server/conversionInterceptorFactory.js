function conversionInterceptorFactory(jsonToProtobuf, protobufToJson, rpcMethod) {
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
