#version 330 core

//in vec4 out_color_vertex;
in vec2 out_tex_coords;

uniform sampler2D texture_sampler_1;
uniform sampler2D texture_sampler_2;

out vec4 frag_color;

void main()
{
    vec4 tex_sample_1 = texture( texture_sampler_1, out_tex_coords );
    vec4 tex_sample_2 = texture( texture_sampler_2, out_tex_coords );
    frag_color = mix( tex_sample_1, tex_sample_2, 0.5 );
}