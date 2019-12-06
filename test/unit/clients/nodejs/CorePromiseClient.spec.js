const CorePromiseClient = require('../../../../clients/nodejs/CorePromiseClient');

describe('CorePromiseClient', () => {
  let corePromiseClient;
  let request;
  let response;

  beforeEach(function main() {
    request = 'test request';
    response = 'test response';

    corePromiseClient = new CorePromiseClient('localhost');
    corePromiseClient.client = {
      sendTransaction: this.sinon.stub().resolves(response),
      getTransaction: this.sinon.stub().resolves(response),
      getBestBlockHeight: this.sinon.stub().resolves(response),
    };
  });

  describe('#sendTransaction', () => {
    it('should send transaction', async () => {
      const result = await corePromiseClient.sendTransaction(request);

      expect(result).to.equal(response);
      expect(corePromiseClient.client.sendTransaction).to.be.calledOnceWith(request);
    });

    it('should throw an error when metadata is not an object', async () => {
      try {
        corePromiseClient.sendTransaction({}, 'metadata');

        expect.fail('Error was not thrown');
      } catch (e) {
        expect(e.message).to.equal('metadata must be an object');
      }
    });
  });

  describe('#getTransaction', () => {
    it('should get transaction', async () => {
      const result = await corePromiseClient.getTransaction(request);

      expect(result).to.equal(response);
      expect(corePromiseClient.client.getTransaction)
        .to.be.calledOnceWith(request);
    });

    it('should throw an error when metadata is not an object', async () => {
      try {
        corePromiseClient.getTransaction({}, 'metadata');

        expect.fail('Error was not thrown');
      } catch (e) {
        expect(e.message).to.equal('metadata must be an object');
      }
    });
  });

  describe('#getBestBlockHeight', () => {
    it('should get best block height', async () => {
      const result = await corePromiseClient.getBestBlockHeight(request);

      expect(result).to.equal(response);
      expect(corePromiseClient.client.getBestBlockHeight).to.be.calledOnceWith(request);
    });

    it('should throw an error when metadata is not an object', async () => {
      try {
        corePromiseClient.getBestBlockHeight({}, 'metadata');

        expect.fail('Error was not thrown');
      } catch (e) {
        expect(e.message).to.equal('metadata must be an object');
      }
    });
  });
});
