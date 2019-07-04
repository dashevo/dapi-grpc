const grpc = require('grpc');

const { InterceptingCall } = grpc;

function conversionInterceptorFactory(jsonToProtobuf, protobufToJson) {
  return function interceptor(options, nextCall) {
    const methods = {
      start(metadata, listener, nextStart) {
        nextStart(metadata, {
          onReceiveMessage(jsonResponse, next) {
            if (!jsonResponse) {
              return next();
            }

            const message = jsonToProtobuf(jsonResponse);

            return next(message);
          },
        });
      },
      sendMessage(message, next) {
        next(protobufToJson(message));
      },
    };
    return new InterceptingCall(nextCall(options), methods);
  };
}

module.exports = conversionInterceptorFactory;
