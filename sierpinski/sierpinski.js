
var x = 0;

function setup() {
  var canvas = createCanvas(600, 600);
  canvas.parent('canvasCont');
  background(150);

}

function draw() {
  // ellipse(x, height/2, 20, 20);
  // x += 1;
}

// =================================================== Sierpinski constructor
function Sierpinski (Depth, A, B, C) {
	this.depth = Depth;
	this.a = A;
	this.b = B;
	this.c = C;
}
