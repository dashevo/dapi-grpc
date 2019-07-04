const CorePromiseClient = require('./clients/nodejs/CorePromiseClient');
const TransactionsFilterStreamPromiseClient = require('./clients/nodejs/TransactionsFilterStreamPromiseClient');
const coreMessages = require('./clients/nodejs/core_pb');
const transactionsFilterStreamMessages = require('./clients/nodejs/transactions_filter_stream_pb');
const loadPackageDefinition = require('./src/loadPackageDefinition');

const jsonToProtobufFactory = require('./src/converters/jsonToProtobufFactory');
const protobufToJson = require('./src/converters/protobufToJson');

const conversionInterceptorFactory = require('./src/interceptors/server/conversionInterceptorFactory');

module.exports = Object.assign({
  CorePromiseClient,
  TransactionsFilterStreamPromiseClient,
  loadPackageDefinition,
  converters: {
    jsonToProtobufFactory,
    protobufToJson,
  },
  interceptors: {
    server: {
      conversionInterceptorFactory,
    },
  },
}, coreMessages, transactionsFilterStreamMessages);
