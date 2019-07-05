const isPlainObject = require('lodash.isplainobject');

const { objectKeysToCamelCase } = require('./objectKeysCaseConverter');

/**
 * Convert snake cased json object to protobuf message (factory)
 *
 * @param MessageClass
 * @param fieldConversionMap
 *
 * @returns {jsonToProtobuf}
 */
function jsonToProtobufFactory(MessageClass, fieldConversionMap = {}) {
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
    const convertedObject = objectKeysToCamelCase(object);

    const message = new MessageClass();

    Object.keys(convertedObject)
      .forEach((key) => {
        let value = convertedObject[key];

        // Recursively convert object to protobuf type using mappings
        if (isPlainObject(value)) {
          value = fieldConversionMap[key](value);
        }

        const setterName = `set${key[0].toUpperCase()}${key.substring(1, key.length)}`;
        message[setterName](value);
      });

    return message;
  }

  return jsonToProtobuf;
}

module.exports = jsonToProtobufFactory;
