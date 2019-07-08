const CorePromiseClient = require('./clients/nodejs/CorePromiseClient');
const TransactionsFilterStreamPromiseClient = require('./clients/nodejs/TransactionsFilterStreamPromiseClient');

const coreRoot = require('./clients/nodejs/core_pb');
const transactionsFilterStreamRoot = require('./clients/nodejs/transactions_filter_stream_pb');

const loadPackageDefinition = require('./src/loadPackageDefinition');
const jsonToProtobufFactory = require('./src/converters/jsonToProtobufFactory');
const protobufToJson = require('./src/converters/protobufToJsonFactory');

module.exports = Object.assign({
  CorePromiseClient,
  TransactionsFilterStreamPromiseClient,
  utils: {
    loadPackageDefinition,
    jsonToProtobufFactory,
    protobufToJson,
  },
}, coreRoot.org.dash.platform.dapi, transactionsFilterStreamRoot.org.dash.platform.dapi);
