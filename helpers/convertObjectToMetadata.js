const { Metadata } = require('grpc');

/**
 * Converts any JavaScript object to grpc metadata
 * @param {Object} obj
 * @returns {module:grpc.Metadata}
 */
function convertObjectToMetadata(obj) {
  const meta = new Metadata();
  Object.keys(obj).forEach((key) => {
    meta.set(key, obj[key]);
  });
  return meta;
}

module.exports = convertObjectToMetadata;
