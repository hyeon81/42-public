import { Trim } from '@miaooo/class-transformer-trim';
import { ApiProperty } from '@nestjs/swagger';
import { IsNotEmpty, IsString, IsUUID } from 'class-validator';
import { $Enums } from '@prisma/client';

class Invite {
	@IsNotEmpty()
	@IsUUID()
	@Trim()
	@ApiProperty({ description: 'Channel id' })
	channelId: string;

	@IsNotEmpty()
	@IsUUID()
	@Trim()
	@ApiProperty({ description: 'User id' })
	userId: string;

	@IsNotEmpty()
	@IsString()
	@Trim()
	@ApiProperty({ description: 'Nickname to invite' })
	nickname: string;

	@IsNotEmpty()
	@IsString()
	@Trim()
	@ApiProperty({ description: 'Game mode' })
	mode: $Enums.GameMode;
}

export default Invite;
