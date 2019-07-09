/**
 * Converts protobuf message to a JSON (factory)
 *
 * @param MessageClass
 *
 * @returns {Object}
 */
function protobufToJsonFactory(MessageClass, GRPCMessageClass) {
  /**
   * Converts protobuf message to a JSON
   *
   * @typedef protobufToJson
   *
   * @param message
   *
   * @returns {Object}
   */
  function protobufToJson(message) {
    const messageBinary = message.serializeBinary();
    const grpcMessage = GRPCMessageClass
      .decode(messageBinary);

    return GRPCMessageClass.toObject(grpcMessage, {
      bytes: Uint8Array,
    });
  }

  return protobufToJson;
}

module.exports = protobufToJsonFactory;
