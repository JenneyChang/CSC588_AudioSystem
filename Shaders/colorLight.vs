// Uniforms
uniform mat4 world_matrix;
uniform mat4 view_matrix;
uniform mat4 proj_matrix;
uniform vec4 color;
uniform vec3 camPos;

// Attributes
layout (location = ATTRIB_LOC_VERT) in vec4 vert;
layout (location = ATTRIB_LOC_NORMS) in vec3 norms;

// Varying
out VS_OUT
{
	vec4 vFragColor;
} vs_out;


void main(void)
{
	vec4 wPos = vec4(world_matrix * vert);
	vec3 wNorm = mat3(transpose(inverse(world_matrix))) * norms;

	gl_Position = proj_matrix * view_matrix * world_matrix * vert;

	vec3 lightDir = normalize(camPos);
	vec3 viewDir = normalize(camPos - vec3(wPos));

	vec3 vhalf = normalize(viewDir + lightDir);
	float specular = pow(clamp(dot(vhalf, wNorm), 0.0f, 1.0f), 8.0f);
	float diffuse = clamp(dot(normalize(wNorm), lightDir), 0.0f, 1.0f);

	vs_out.vFragColor = (diffuse + specular) * color;
}