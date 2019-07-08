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
    const o = MessageClass.toObject(message);
    // console.log('client send a message');
    // console.dir(o);
    return o;
  }

  return protobufToJson;
}

module.exports = protobufToJsonFactory;
