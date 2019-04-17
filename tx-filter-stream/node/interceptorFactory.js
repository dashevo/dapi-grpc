const grpc = require('grpc');

const { InterceptingCall } = grpc;

function createJsonToProtobufConverter(MessageClass) {
  return function interceptor (options, nextCall) {
    const methods = {
      start(metadata, listener, next) {
        next(metadata, {
          onReceiveMessage(jsonResponse, next) {
            const response = new MessageClass();
            Object.keys(jsonResponse).forEach((key) => {
              const setterName = `set${key[0].toUpperCase()}${key.substring(1,key.length)}`;
              response[setterName](jsonResponse[key]);
            });
            next(response);
          }
        });
      },
    };
    return new InterceptingCall(nextCall(options), methods);
  };
}

module.exports = {
  createJsonToProtobufConverter
};
