'use strict';

const expect = require('chai').expect;

const fss = require('../index');

describe('#indexOf', function() {
  it('should find two substrings', function() {
    var result = fss.indexOf('coocoocoo', 'oocoo').toString();
    expect(result).to.equal('1,4');
  });
  it('should find one substring', function() {
    var result = fss.indexOfSkip('coocoocoo', 'oocoo').toString();
    expect(result).to.equal('1');
  });
  it('should find three substrings', function() {
    var result = fss.indexOf('coocoocoocoo', 'oocoo').toString();
    expect(result).to.equal('1,4,7');
  });
  it('should find two substrings', function() {
    var result = fss.indexOfSkip('coocoocoocoo', 'oocoo').toString();
    expect(result).to.equal('1,7');
  });
  it('should find four substrings', function() {
    var result = fss.indexOf('HERE IS A SIMPLE EXAMPLE, WHICH CONTAINS MULTIPLE EXAMPLES. SIXLEE IS A WRONG WORD. EXAMPLEEXAMPLE', 'EXAMPLE').toString();
    expect(result).to.equal('17,50,84,91');
  });
  it('should find four substrings', function() {
    var result = fss.indexOfSkip('HERE IS A SIMPLE EXAMPLE, WHICH CONTAINS MULTIPLE EXAMPLES. SIXLEE IS A WRONG WORD. EXAMPLEEXAMPLE', 'EXAMPLE').toString();
    expect(result).to.equal('17,50,84,91');
  });
});

describe('#lastIndexOf', function() {
  it('should find two substrings', function() {
    var result = fss.lastIndexOf('coocoocoo', 'oocoo').toString();
    expect(result).to.equal('4,1');
  });
  it('should find three substrings', function() {
    var result = fss.lastIndexOf('coocoocoocoo', 'oocoo').toString();
    expect(result).to.equal('7,4,1');
  });
  it('should find three substrings', function() {
    var result = fss.lastIndexOf('coocoocoocoo', 'oocoo', 1).toString();
    expect(result).to.equal('7,4,1');
  });
  it('should find two substrings', function() {
    var result = fss.lastIndexOf('coocoocoocoo', 'oocoo', 2).toString();
    expect(result).to.equal('7,4');
  });
});

describe('#utf16IndexOf', function() {
  it('should find two substrings', function() {
    var result = fss.utf16IndexOf(Buffer.from('coocoocoo', 'utf16le'), Buffer.from('oocoo', 'utf16le')).toString();
    expect(result).to.equal('1,4');
  });
  it('should find one substring', function() {
    var result = fss.utf16IndexOfSkip(Buffer.from('coocoocoo', 'utf16le'), Buffer.from('oocoo', 'utf16le')).toString();
    expect(result).to.equal('1');
  });
  it('should find three substrings', function() {
    var result = fss.utf16IndexOf(Buffer.from('coocoocoocoo', 'utf16le'), Buffer.from('oocoo', 'utf16le')).toString();
    expect(result).to.equal('1,4,7');
  });
  it('should find two substrings', function() {
    var result = fss.utf16IndexOfSkip(Buffer.from('coocoocoocoo', 'utf16le'), Buffer.from('oocoo', 'utf16le')).toString();
    expect(result).to.equal('1,7');
  });
  it('should find four substrings', function() {
    var result = fss.utf16IndexOf(Buffer.from('HERE IS A SIMPLE EXAMPLE, WHICH CONTAINS MULTIPLE EXAMPLES. SIXLEE IS A WRONG WORD. EXAMPLEEXAMPLE', 'utf16le'), Buffer.from('EXAMPLE', 'utf16le')).toString();
    expect(result).to.equal('17,50,84,91');
  });
  it('should find four substrings', function() {
    var result = fss.utf16IndexOfSkip(Buffer.from('HERE IS A SIMPLE EXAMPLE, WHICH CONTAINS MULTIPLE EXAMPLES. SIXLEE IS A WRONG WORD. EXAMPLEEXAMPLE', 'utf16le'), Buffer.from('EXAMPLE', 'utf16le')).toString();
    expect(result).to.equal('17,50,84,91');
  });
});

describe('#utf16LastIndexOf', function() {
  it('should find two substrings', function() {
    var result = fss.utf16LastIndexOf(Buffer.from('coocoocoo', 'utf16le'), Buffer.from('oocoo', 'utf16le')).toString();
    expect(result).to.equal('4,1');
  });
  it('should find three substrings', function() {
    var result = fss.utf16LastIndexOf(Buffer.from('coocoocoocoo', 'utf16le'), Buffer.from('oocoo', 'utf16le')).toString();
    expect(result).to.equal('7,4,1');
  });
  it('should find three substrings', function() {
    var result = fss.utf16LastIndexOf(Buffer.from('coocoocoocoo', 'utf16le'), Buffer.from('oocoo', 'utf16le'), 1).toString();
    expect(result).to.equal('7,4,1');
  });
  it('should find two substrings', function() {
    var result = fss.utf16LastIndexOf(Buffer.from('coocoocoocoo', 'utf16le'), Buffer.from('oocoo', 'utf16le'), 2).toString();
    expect(result).to.equal('7,4');
  });
});
