const path = require('path');
const grpc = require('grpc');
const protoLoader = require('@grpc/proto-loader');
const jsonToProtobufInterceptorFactory = require('./jsonToProtobufInterceptorFactory');
const { RawTransaction } = require('./tx_filter_stream_pb');

const protoPath = path.join(__dirname, '../tx_filter_stream.proto');

const definition = protoLoader.loadSync(protoPath, {
  keepCase: true,
  longs: String,
  enums: String,
  bytes: Array,
  defaults: true,
});

const descriptor = grpc.loadPackageDefinition(definition);
const {
  TransactionsFilterStream: TransactionsFilterStreamNodeJSClient,
} = descriptor.org.dash.platform.dapi;

const getNewTransactionsByFilterOptions = {
  interceptors: [jsonToProtobufInterceptorFactory(RawTransaction)],
};

class TransactionsFilterStreamClient {
  /**
   * @param {string} hostname
   * @param {?Object} credentials
   * @param {?Object} options
   */
  constructor(hostname, credentials = grpc.credentials.createInsecure(), options = {}) {
    this.client = new TransactionsFilterStreamNodeJSClient(hostname, credentials, options);
  }

  /**
   * @param {BloomFilter} bloomFilter The request proto
   * @param {?Object<string, string>} metadata User defined call metadata
   * @return {!grpc.web.ClientReadableStream<!RawTransaction>|undefined}
   *     The XHR Node Readable Stream
   */
  getNewTransactionsByFilter(bloomFilter, metadata) {
    const obj = bloomFilter.toObject();
    this.client.getNewTransactionsByFilter(obj, getNewTransactionsByFilterOptions);
  }
}

module.exports = TransactionsFilterStreamClient;
