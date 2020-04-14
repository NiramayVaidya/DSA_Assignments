float convert_1(float);

float convert(float temp_fahr) {
	float temp_celc;
	temp_celc = (5.0 / 9.0) * convert_1(temp_fahr);
	return temp_celc;
}
