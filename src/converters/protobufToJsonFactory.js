/**
 * Converts protobuf message to a JSON (factory)
 *
 * @param MessageClass
 *
 * @returns {Object}
 */
function protobufToJsonFactory(MessageClass) {
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
    return MessageClass.toObject(message);
  }

  return protobufToJson;
}

module.exports = protobufToJsonFactory;
