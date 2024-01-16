import { Injectable } from '@nestjs/common';
import PrismaService from 'common/prisma/prisma.service';
import * as Dto from './dto';
import { MessageBody } from '@nestjs/websockets';
import { plainToClass } from 'class-transformer';
import { validate } from 'class-validator';

@Injectable()
class ChannelService {
	constructor(private readonly prismaService: PrismaService) {}

	async getChannelList(): Promise<Dto.Response.Channel[]> {
		try {
			const channelList: Dto.Response.Channel[] = await this.prismaService.channel.findMany({
				select: {
					id: true,
					title: true,
					visibility: true,
				},
			});

			return channelList;
		} catch (error) {
			throw new Error(error.message);
		}
	}

	async getChannel(id: string): Promise<Dto.Response.Channel> {
		try {
			const channelDetail = await this.prismaService.channel.findUnique({
				where: { id },
				select: {
					id: true,
					title: true,
					visibility: true,
				},
			});
			return channelDetail;
		} catch (error) {
			throw new Error(error.message);
		}
	}

	async createChannel(createRequestDto: Dto.Request.Create): Promise<Dto.Response.Channel> {
		try {
			return await this.prismaService.channel.create({
				data: { ...createRequestDto },
			});
		} catch (error) {
			throw new Error(error.message);
		}
	}

	async editChannel(@MessageBody() data) {
		try {
			const updateChannelDto = plainToClass(Dto.Request.Create, data);
			const error = await validate(updateChannelDto);

			if (error.length > 0) {
				throw new Error('Failed validation: ' + JSON.stringify(error));
			}

			const id = data.channelId;
			await this.prismaService.channel.update({
				where: { id },
				data: updateChannelDto,
				select: {
					id: true,
					updatedAt: true,
				},
			});
		} catch (error) {
			throw new Error('Failed to update channel info: ' + error.message);
		}
	}

	async validatePassword(id: string, password: string): Promise<boolean> {
		try {
			const channel = await this.prismaService.channel.findUnique({
				where: { id },
			});

			return channel.password === password;
		} catch (error) {
			throw new Error(error.message);
		}
	}
}

export default ChannelService;
