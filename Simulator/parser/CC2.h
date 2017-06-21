var:2
float accel;
float brake;

input:0

output:0

CAN_input:0

CAN_output:1
10:0x7FF:2
accel ACCEL
brake BRAKE

code:
{
	//cannot use:
	//car_output[SPEED]
	//can use:
	//Simulator/engine/auto_generated_files/data_list.hh - excluding those above
	//car_output[TRACK_WIDTH], car_output[YAW], car_output[TRACK_ANGLE], car_output[DISTANCE]

	float speed = internal_data[0];
	//float angle = car_output[ANGLE];
	brake = 0.0;
	accel = 0.05;

	if (speed > 7)
		accel -= 0.3;

}
