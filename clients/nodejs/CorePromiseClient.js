const grpc = require('grpc');
const { promisify } = require('util');
const conversionInterceptorFactory = require('../../src/interceptors/client/conversionInterceptorFactory');
const loadPackageDefinition = require('../../src/loadPackageDefinition');
const {
  LastUserStateTransitionHashResponse,
  BlockHeadersWithChainLocksResponse,
} = require('./core_pb');
const isObject = require('../../src/isObject');
const convertObjectToMetadata = require('../../src/convertObjectToMetadata');

const jsonToProtobufFactory = require('../../src/converters/jsonToProtobufFactory');
const protobufToJson = require('../../src/converters/protobufToJson');

const {
  Core: CoreNodeJSClient,
} = loadPackageDefinition('Core');

const getLastUserStateTransitionHashOptions = {
  interceptors: [
    conversionInterceptorFactory(
      jsonToProtobufFactory(LastUserStateTransitionHashResponse),
      protobufToJson,
    ),
  ],
};

const subscribeToBlockHeadersWithChainLocksOptions = {
  interceptors: [
    conversionInterceptorFactory(
      jsonToProtobufFactory(BlockHeadersWithChainLocksResponse),
      protobufToJson,
    ),
  ],
};

class CorePromiseClient {
  /**
   * @param {string} hostname
   * @param {?Object} credentials
   * @param {?Object} options
   */
  constructor(hostname, credentials = grpc.credentials.createInsecure(), options = {}) {
    this.client = new CoreNodeJSClient(hostname, credentials, options);

    this.client.getLastUserStateTransitionHash = promisify(
      this.client.getLastUserStateTransitionHash.bind(this.client),
    );

    this.client.subscribeToBlockHeadersWithChainLocks = promisify(
      this.client.subscribeToBlockHeadersWithChainLocks.bind(this.client),
    );
  }

  /**
   * @param {!LastUserStateTransitionHashRequest} lastUserStateTransitionHashRequest
   * @param {?Object<string, string>} metadata
   * @return {Promise<!LastUserStateTransitionHashResponse>}
   */
  getLastUserStateTransitionHash(lastUserStateTransitionHashRequest, metadata = {}) {
    if (!isObject(metadata)) {
      throw new Error('metadata must be an object');
    }

    return this.client.getLastUserStateTransitionHash(
      lastUserStateTransitionHashRequest,
      convertObjectToMetadata(metadata),
      getLastUserStateTransitionHashOptions,
    );
  }

  /**
   * @param {!BlockHeadersWithChainLocksRequest} blockHeadersWithChainLocksRequest
   * @param {?Object<string, string>} metadata
   * @return {!grpc.web.ClientReadableStream<!BlockHeadersWithChainLocksResponse>|undefined}
   *     The XHR Node Readable Stream
   */
  subscribeToBlockHeadersWithChainLocks(blockHeadersWithChainLocksRequest, metadata = {}) {
    if (!isObject(metadata)) {
      throw new Error('metadata must be an object');
    }

    return this.client.subscribeToBlockHeadersWithChainLocks(
      blockHeadersWithChainLocksRequest,
      convertObjectToMetadata(metadata),
      subscribeToBlockHeadersWithChainLocksOptions,
    );
  }
}

module.exports = CorePromiseClient;
