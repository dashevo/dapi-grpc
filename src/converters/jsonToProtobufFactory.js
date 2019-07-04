const camelCase = require('lodash.camelcase');

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
   * @returns {jspb.Message}
   */
  function jsonToProtobuf(object) {
    const message = new MessageClass();

    Object.keys(object).forEach((key) => {
      const camelKey = camelCase(key);
      const setterName = `set${camelKey[0].toUpperCase()}${camelKey.substring(1, key.length)}`;
      message[setterName](object[key]);
    });

    return message;
  }

  return jsonToProtobuf;
}

module.exports = jsonToProtobufFactory;
