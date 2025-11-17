uniform float uSliceStart;
uniform float uSliceArc;

varying vec3 vPosition;


void main()
{
    // float uSliceStart = 1.0;
    // float uSliceArc = 1.5;

    float angle = atan(vPosition.y, vPosition.x);
    angle -= uSliceStart;
    angle = mod(angle, PI * 2.0);


    if(angle > 0.0 && angle < uSliceArc)
        discard;

    // if(!gl_FrontFacing)
    //     csm_FragColor = vec4(0.75, 0.15, 0.3, 1.0);

    // csm_FragColor = vec4(vec3(angle), 1.0);
    float csm_Slice;
}