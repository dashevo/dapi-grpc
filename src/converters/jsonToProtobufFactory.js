/**
 * Convert snake cased json object to protobuf message (factory)
 *
 * @param MessageClass
 *
 * @returns {jsonToProtobuf}
 */
function jsonToProtobufFactory(MessageClass) {
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
    return MessageClass.fromObject(object);
  }

  return jsonToProtobuf;
}

module.exports = jsonToProtobufFactory;
