import { ApiProperty } from '@nestjs/swagger';
import { Participant } from '@prisma/client';
import { $Enums } from '@prisma/client';

class ParticipantModel implements Participant {
	@ApiProperty({ description: 'Participant id generated by database' })
	id: string;

	@ApiProperty({ description: 'Channel id' })
	channelId: string;

	@ApiProperty({ description: 'User id' })
	userId: string;

	@ApiProperty({ description: 'Participant role' })
	role: $Enums.ParticipantRole;

	@ApiProperty({ required: false })
	createdAt: Date;

	@ApiProperty({ required: false })
	updatedAt: Date;
}

export default ParticipantModel;
