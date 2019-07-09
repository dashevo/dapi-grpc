/**
 * Convert snake cased json object to protobuf message (factory)
 *
 * @param MessageClass
 *
 * @returns {jsonToProtobuf}
 */
function jsonToProtobufFactory(MessageClass, GRPCMessageClass) {
  /**
   * Convert snake cased json object to protobuf message
   *
   * @typedef jsonToProtobuf
   *
   * @param {Object} object
   *
   * @returns {*}
   */
  function jsonToProtobuf(object) {
    const grpcMessage = GRPCMessageClass.fromObject(object);
    const grpcMessageBinary = GRPCMessageClass
      .encode(grpcMessage)
      .finish();

    return MessageClass.deserializeBinary(grpcMessageBinary);
  }

  return jsonToProtobuf;
}

module.exports = jsonToProtobufFactory;
