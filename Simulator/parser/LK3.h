var:1
float steering;

input:0

output:0

CAN_input:0

CAN_output:1
10:0x7FE:1
steering STEER

code:
{
	//cannot use:
	//car_output[TRACK_ANGLE]
	//car_output[TRACK_WIDTH]
	//car_output[YAW]
	//car_output[DISTANCE]
	//Simulator/engine/auto_generated_files/data_list.hh - excluding those above

	//sensor data
	float track_width = internal_data[0];
	float distance = internal_data[1];
	float track_angle = internal_data[2];
	float yaw = internal_data[3];

	//get difference of angle
	float angle = track_angle - yaw;
	float pi = 3.141592;
	while(angle > pi)
		angle -= 2*pi;
	while(angle < -pi)
		angle += 2*pi;

	//calculate steering value
	float SC = 1.0;
	if(track_width == 0.0)
		steering = 0.0;
	else
		steering = angle - SC*distance/track_width;
	if(distance < -0.08)
		steering += 0.06;

	if(distance > 0.08)
		steering -= 0.06;



}
