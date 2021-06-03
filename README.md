Fast String Search
=================================

[![CI](https://github.com/magiclen/node-fast-string-search/actions/workflows/ci.yml/badge.svg)](https://github.com/magiclen/node-fast-string-search/actions/workflows/ci.yml)

This module can search substrings in a string by using N-API and boyer-moore-magiclen. The result of benchmark shows that this module is **10 times faster** than the `indexOf` function of a Node.js string.

## Initialization

Import this module by using `require` function.

```javascript
const fss = require('fast-string-search');
```

## Usage

### indexOf

Full text search in a string.

```javascript
var a = fss.indexOf('coocoocoocoo', 'oocoo'); // [1, 4, 7]
```

You can also set the offset of characters and the number of substrings you want to find.

```javascript
var a = fss.indexOf(source, pattern, offset, limit);
```

The default value of `offset` is `0`, and the default value of `limit` is `1000`.

### indexOfSkip

Normal text search in a string.

```javascript
var a = fss.indexOfSkip('coocoocoocoo', 'oocoo'); // [1, 7]
```

### lastIndexOf

Full text search from the end of a string.

```javascript
var a = fss.lastIndexOf('coocoocoocoo', 'oocoo'); // [7, 4, 1]
```

### utf16IndexOf/utf16IndexOfSkip/utf16LastIndexOf

```javascript
var a = fss.utf16IndexOf(Buffer.from('coocoocoocoo', 'utf16le'), Buffer.from('oocoo', 'utf16le')); // [1, 4, 7]
```

## Tests

To run the test suite, first install the dependencies, then run `npm test`:

```bash
npm install
npm test
```

## Benchmark

To run the benchmark suite, first install the dependencies, then run `npm run benchmark`:

```bash
npm install
npm run benchmark
```

Here is my result,

```bash
Full Text Search
  - 87 milliseconds
  ✓ natively search text(indexOf) (87ms)
  - 7 milliseconds
  ✓ Use FSS to search text

Normal Text Search
  - 35 milliseconds
  ✓ natively search text(indexOf)
  - 46 milliseconds
  ✓ natively search text(RegExp) (46ms)
  - 6 milliseconds
  ✓ Use FSS to search text
```

## License

[MIT](LICENSE)
