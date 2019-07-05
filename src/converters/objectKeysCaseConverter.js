const camelCase = require('lodash.camelcase');
const snakeCase = require('lodash.snakecase');
const isPlainObject = require('lodash.isplainobject');

/**
 * @private
 *
 * Convert object keys
 *
 * @param {Object} object
 * @param {function(string)} convertFunction
 *
 * @returns {Object}
 */
function convertObjectKeys(object, convertFunction) {
  return Object.keys(object)
    .reduce((result, key) => {
      let value = object[key];

      // Recursively convert object keys
      if (isPlainObject(value)) {
        value = convertObjectKeys(value, convertFunction);
      }

      // eslint-disable-next-line no-param-reassign
      result[convertFunction(key)] = value;

      return result;
    }, {});
}


/**
 * Convert object keys to snake case
 *
 * @param {Object} object
 *
 * @returns {Object}
 */
function objectKeysToSnakeCase(object) {
  return convertObjectKeys(object, snakeCase);
}


/**
 * Convert object keys to camel case
 *
 * @param {Object} object
 *
 * @returns {Object}
 */
function objectKeysToCamelCase(object) {
  return convertObjectKeys(object, camelCase);
}

module.exports = {
  objectKeysToSnakeCase,
  objectKeysToCamelCase,
};
