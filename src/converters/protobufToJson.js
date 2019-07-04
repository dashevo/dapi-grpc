const snakeCase = require('lodash.snakecase');

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

  return Object.keys(messageObject)
    .reduce((result, key) => Object.assign(
      {},
      result,
      {
        [snakeCase(key)]: messageObject[key],
      },
    ), {});
}

module.exports = protobufToJson;
