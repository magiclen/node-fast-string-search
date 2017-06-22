'use strict';

const expect = require('chai').expect;
const mlog = require('mocha-logger');

const fss = require('../index');

describe('Search', function() {
  var a = '';
  for (let i = 0; i < 100000; ++i) {
    a += 'HERE IS A SIMPLE EXAMPLE, WHICH CONTAINS MULTIPLE EXAMPLES. SIXLEE IS A WRONG WORD. EXAMPLEEXAMPLE';
  }
  var p = 'EXAMPLE';
  var startTime, endTime;

  it('natively search text', function() {
    var s = a;
    startTime = Date.now();
    var sum = 0;
    var index;
    var offset = 0;
    var indexArray = [];
    while (true) {
      index = s.indexOf(p, offset);
      if (index < 0) {
        break;
      }
      indexArray.push(index);
      offset = index + 1;
    }
    var sum = indexArray.length;
    endTime = Date.now();
    mlog.log(endTime - startTime, 'milliseconds');
  });

  it('Using FSS to search text', function() {
    startTime = Date.now();
    var indexArray = fss.indexOf(a, p);
    var sum = indexArray.length;
    endTime = Date.now();
    mlog.log(endTime - startTime, 'milliseconds');
  });
});
