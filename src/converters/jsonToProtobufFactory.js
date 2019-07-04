const camelCase = require('lodash.camelcase');

function jsonToProtobufFactory(MessageClass) {
  function convert(object) {
    const message = new MessageClass();

    Object.keys(object).forEach((key) => {
      const camelKey = camelCase(key);
      const setterName = `set${camelKey[0].toUpperCase()}${camelKey.substring(1, key.length)}`;
      message[setterName](object[key]);
    });

    return message;
  }

  return convert;
}

module.exports = jsonToProtobufFactory;
