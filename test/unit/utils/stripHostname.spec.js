const stripHostname = require('../../../lib/utils/stripHostname');

describe('stripHostname', () => {
  let hostname;

  beforeEach(() => {
    hostname = 'http://ip:3030/';
  });

  it('should strip everything and leave only hostname:port pair', () => {
    const result = stripHostname(hostname);

    expect(result).to.equal('ip:3030');
  });

  it('should strip everything and leave only ip:port pair', () => {
    hostname = 'http://127.0.0.1:3030/?some=params';

    const result = stripHostname(hostname);

    expect(result).to.equal('127.0.0.1:3030');
  });

  it('should strip https URL and leave only hostname:port pair', () => {
    hostname = 'https://ip:3030/';

    const result = stripHostname(hostname);

    expect(result).to.equal('ip:3030');
  });

  it('should leave hostname:port pair as is', () => {
    hostname = 'ip:3030';

    const result = stripHostname(hostname);

    expect(result).to.equal('ip:3030');
  });


  it('should leave ip:port pair as is', () => {
    hostname = '127.0.0.1:3030';

    const result = stripHostname(hostname);

    expect(result).to.equal(hostname);
  });
});
