'use strict';

const expect = require('chai').expect;
const mlog = require('mocha-logger');

const fss = require('../index');

describe('Full Text Search', function() {
  var a = '';
  for (let i = 0; i < 1000000; ++i) {
    a += 'COO';
  }
  var p = 'OOCOO';
  var startTime, endTime;

  it('natively search text(indexOf)', function() {
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

  it('Use FSS to search text', function() {
    startTime = Date.now();
    var indexArray = fss.indexOf(a, p, 0, 1000000);
    var sum = indexArray.length;
    endTime = Date.now();
    mlog.log(endTime - startTime, 'milliseconds');
  });
});

describe('Normal Text Search', function() {
  var a = '';
  for (let i = 0; i < 1000000; ++i) {
    a += 'COO';
  }
  var p = 'OOCOO';
  var startTime, endTime;

  it('natively search text(indexOf)', function() {
    var s = a;
    startTime = Date.now();
    var sum = 0;
    var index;
    var offset = 0;
    var indexArray = [];
    var pLength = p.length;
    while (true) {
      index = s.indexOf(p, offset);
      if (index < 0) {
        break;
      }
      indexArray.push(index);
      offset = index + pLength;
    }
    var sum = indexArray.length;
    endTime = Date.now();
    mlog.log(endTime - startTime, 'milliseconds');
  });

  it('natively search text(RegExp)', function() {
    var s = a;
    startTime = Date.now();
    var regex = /OOCOO/g;
    var sum = 0;
    var index;
    var match = 0;
    var indexArray = [];
    while (match = regex.exec(s)) {
      indexArray.push(match.index);
    }
    var sum = indexArray.length;
    endTime = Date.now();
    mlog.log(endTime - startTime, 'milliseconds');
  });

  it('Use FSS to search text', function() {
    startTime = Date.now();
    var indexArray = fss.indexOfSkip(a, p, 0, 500000);
    var sum = indexArray.length;
    endTime = Date.now();
    mlog.log(endTime - startTime, 'milliseconds');
  });
});
