let angle = 0;
let w = 30;
let ma;
let maxD;

function setup() {
  createCanvas(600,600,WEBGL);
  ortho_angle = atan(1/sqrt(2));
  maxD = dist(0,0,200,200);
}


function draw() {
  background(100);
  fill(255);

  // Camera and perspective settings
  ortho(-500,500,-400,400,-2000,2000);
  // let camX = map(mouseX,0,width,-width/2,width/2);
  // let camZ = map(mouseY,0,height,-800,0);
  // camera(camX,-900,camZ, 0,0,0,0,1,0);

  // Canvas Transformations
  rotateX(-PI / 8);
  rotateY(ortho_angle);


  // Drawing the cubes
  for(let z = 0; z <= height; z += w){
    for(let x = 0; x <= width; x += w){
      push();
      let d = dist(x, z, width/2,height/2);
      let offset = map(d, 10, maxD, 10, -10);
      let a = angle + offset;
      let h = map(sin(a), -1, 1, 1, 200);
      let h_col = map(h, 1, 200, 0, 255);
      // fill(h, a, d);
      translate(x - width/2, 0, z - height/2);
      //ambientLight(0, 0, 255, 100);
      ambientMaterial(random()*255, h_col, random()*255);
      box(w,h,w);
      pop();
    }
  }
  angle += 0.1;
}
