const grpc = require('grpc');
const jsonToProtobufInterceptorFactory = require('./jsonToProtobufInterceptorFactory');
const loadPackageDefinition = require('./loadPackageDefinition');
const { RawTransaction } = require('./tx_filter_stream_pb');
const isObject = require('../../helpers/isObject');
const convertObjectToMetadata = require('../../helpers/convertObjectToMetadata');

const { Metadata } = grpc;

const packageDefinition = loadPackageDefinition();

const {
  TransactionsFilterStream: TransactionsFilterStreamNodeJSClient,
} = packageDefinition.org.dash.platform.dapi;

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
  getNewTransactionsByFilter(bloomFilter, metadata = new Metadata()) {
    let meta = metadata;
    if (isObject(metadata) && !(metadata instanceof Metadata)) {
      meta = convertObjectToMetadata(metadata);
    }
    const obj = bloomFilter.toObject();
    this.client.getNewTransactionsByFilter(obj, meta, getNewTransactionsByFilterOptions);
  }
}

module.exports = TransactionsFilterStreamClient;
