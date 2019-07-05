const { objectKeysToSnakeCase } = require('./objectKeysCaseConverter');

/**
 * Converts protobuf message to a snake cased JSON
 *
 * @typedef protobufToJson
 *
 * @param {jspb.Message} message
 *
 * @returns {Object}
 */
function protobufToJson(message) {
  const messageObject = message.toObject();

  return objectKeysToSnakeCase(messageObject);
}

module.exports = protobufToJson;
