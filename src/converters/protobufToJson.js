const snakeCase = require('lodash.snakecase');

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
