const path = require('path');
const grpc = require('grpc');
const { promisify } = require('util');

const {
  loadPackageDefinition,
  utils: {
    isObject,
    convertObjectToMetadata,
  },
  client: {
    interceptors: {
      jsonToProtobufInterceptorFactory,
    },
    converters: {
      jsonToProtobufFactory,
      protobufToJsonFactory,
    },
  },
} = require('@dashevo/grpc-common');

const {
  org: {
    dash: {
      platform: {
        dapi: {
          LastUserStateTransitionHashRequest: PBJSLastUserStateTransitionHashRequest,
          LastUserStateTransitionHashResponse: PBJSLastUserStateTransitionHashResponse,
          BlockHeadersWithChainLocksRequest: PBJSBlockHeadersWithChainLocksRequest,
          BlockHeadersWithChainLocksResponse: PBJSBlockHeadersWithChainLocksResponse,
          StateTransition: PBJSStateTransition,
          StateTransitionResponse: PBJSStateTransitionResponse,
        },
      },
    },
  },
} = require('./core_pbjs');

const {
  LastUserStateTransitionHashResponse: ProtocLastUserStateTransitionHashResponse,
  BlockHeadersWithChainLocksResponse: ProtocBlockHeadersWithChainLocksResponse,
  StateTransitionResponse: ProtocStateTransitionResponse,
} = require('./core_protoc');

const protoPath = path.join(__dirname, '../protos/core.proto');

const {
  Core: CoreNodeJSClient,
} = loadPackageDefinition(protoPath, 'org.dash.platform.dapi.v0');

const getLastUserStateTransitionHashOptions = {
  interceptors: [
    jsonToProtobufInterceptorFactory(
      jsonToProtobufFactory(
        ProtocLastUserStateTransitionHashResponse,
        PBJSLastUserStateTransitionHashResponse,
      ),
      protobufToJsonFactory(
        PBJSLastUserStateTransitionHashRequest,
      ),
    ),
  ],
};

const subscribeToBlockHeadersWithChainLocksOptions = {
  interceptors: [
    jsonToProtobufInterceptorFactory(
      jsonToProtobufFactory(
        ProtocBlockHeadersWithChainLocksResponse,
        PBJSBlockHeadersWithChainLocksResponse,
      ),
      protobufToJsonFactory(
        PBJSBlockHeadersWithChainLocksRequest,
      ),
    ),
  ],
};

const updateStateTransitionOptions = {
  interceptors: [
    jsonToProtobufInterceptorFactory(
      jsonToProtobufFactory(
        ProtocStateTransitionResponse,
        PBJSStateTransitionResponse,
      ),
      protobufToJsonFactory(
        PBJSStateTransition,
      ),
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

    this.client.updateState = promisify(
      this.client.updateState.bind(this.client),
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

  /**
   *
   * @param {!StateTransition} stateTransition
   * @param {?Object<string, string>} metadata
   * @returns {Promise<!StateTransitionResponse>}
   */
  updateState(stateTransition, metadata = {}) {
    if (!isObject(metadata)) {
      throw new Error('metadata must be an object');
    }

    return this.client.updateState(
      stateTransition,
      convertObjectToMetadata(metadata),
      updateStateTransitionOptions,
    );
  }
}

module.exports = CorePromiseClient;
