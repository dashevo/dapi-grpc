# DAPI GRPC


[![NPM Version](https://img.shields.io/npm/v/@dashevo/dapi-grpc)](https://www.npmjs.com/package/@dashevo/dapi-grpc)
[![Build Status](https://travis-ci.com/dashevo/dapi-grpc.svg?branch=master)](https://travis-ci.com/dashevo/dapi-grpc)
[![Release Date](https://img.shields.io/github/release-date/dashevo/dapi-grpc)](https://github.com/dashevo/dapi-grpc/releases/latest)
[![license](https://img.shields.io/github/license/dashevo/dapi-grpc.svg)](LICENSE)
[![standard-readme compliant](https://img.shields.io/badge/readme%20style-standard-brightgreen)](https://github.com/RichardLitt/standard-readme)

> Decentralized API GRPC definition files and generated clients

## Table of Contents

- [Install](#install)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Install

Ensure you have the latest [NodeJS](https://nodejs.org/en/download/) installed.

#### From repository

Clone the repo:

```shell
git clone https://github.com/dashevo/dapi-grpc
```

Install npm packages:

```shell
npm install
```

#### From NPM

```sh
npm install @dashevo/dapi-grpc
```

## Usage

```js
import { TransactionsFilterStreamClient, BloomFilter } from '@dashevo/dapi-grpc';

const client = new TransactionsFilterStreamClient('http://localhost:8080');

const filter = new BloomFilter();
filter.setBytes('...');

const stream = client.getTransactionsByFilter(filter);

stream.on('data', function(response) {
  console.log(response.getData());
});

stream.on('status', function(status) {
  console.log(status.code);
  console.log(status.details);
  console.log(status.metadata);
});

stream.on('end', function(end) {
  // stream end signal
});
```

## Maintainer

[@shumkov](https://github.com/shumkov)

## Contributing

Feel free to dive in! [Open an issue](https://github.com/dashevo/dapi-grpc/issues/new) or submit PRs.

## License

[MIT](LICENSE) &copy; Dash Core Group, Inc.

