import { AppRouterInstance } from 'next/dist/shared/lib/app-router-context.shared-runtime';
import Phaser from 'phaser';
import { Socket } from 'socket.io-client';

class MainScene extends Phaser.Scene {
	private ball!: Phaser.Physics.Arcade.Image;

	private myPaddle!: Phaser.Physics.Arcade.Image;
	private enemyPaddle!: Phaser.Physics.Arcade.Image;

	private myScore!: Phaser.GameObjects.Text;
	private enemyScore!: Phaser.GameObjects.Text;

	private keys!: Phaser.Types.Input.Keyboard.CursorKeys;

	private isPlaying: boolean = false;

	private navigate!: AppRouterInstance;
	private socket!: Socket;
	private room: string = '';

	constructor(navigate: AppRouterInstance, socket: Socket, room: string) {
		super({ key: 'MainScene', active: true });
		this.events = new Phaser.Events.EventEmitter();
		this.navigate = navigate;
		this.socket = socket;
		this.room = room;
	}

	reset() {
		this.ball.setVisible(false);
		this.ball.setVelocity(0, 0);
		this.ball.setPosition(this.game.canvas.width / 2, this.game.canvas.height / 2);
		this.ball.setVisible(true);
		this.myPaddle.setVelocity(0, 0);
		this.enemyPaddle.setVelocity(0, 0);

		// Add text "press space to ready"

		this.isPlaying = false;

		setTimeout(() => {}, 1000);
	}

	score() {
		if (10 < this.ball.y && this.ball.y < 630) {
			return;
		}

		this.ball.setVelocity(0, 0);

		if (10 < this.ball.y) {
			this.myScore.setText((parseInt(this.myScore.text, 10) + 1).toString());
			this.socket.emit('score', {
				room: this.room,
				score: this.myScore.text,
			});
		}

		this.reset();
	}

	preload() {
		this.load.image('ball', '/ball.png');
		this.load.image('paddle', '/paddle.png');
	}

	initBall() {
		this.ball = this.physics.add.image(
			this.game.canvas.width / 2,
			this.game.canvas.height / 2,
			'ball',
		);
		this.ball.setCollideWorldBounds(true);
		this.ball.setBounce(1, 1);
		this.ball.setVelocity(0, 0);
	}

	initPaddle() {
		this.myPaddle = this.physics.add.image(this.game.canvas.width / 2, 610, 'paddle');
		this.myPaddle.setImmovable(true);
		this.enemyPaddle = this.physics.add.image(this.game.canvas.width / 2, 30, 'paddle');
		this.enemyPaddle.setImmovable(true);
	}

	initScore() {
		this.myScore = this.add
			.text(this.game.canvas.width / 2, (this.game.canvas.height / 4) * 3, '0', {
				fontSize: '32px',
				fontFamily: 'Inter',
				color: '#FFFFFF',
			})
			.setOrigin(0.5, 0.5);
		this.enemyScore = this.add
			.text(this.game.canvas.width / 2, this.game.canvas.height / 4, '0', {
				fontSize: '32px',
				fontFamily: 'Inter',
				color: '#FFFFFF',
			})
			.setOrigin(0.5, 0.5);
	}

	initSocket() {
		this.socket.on('start', response => {
			this.isPlaying = true;
			this.ball.setVelocity(response.ball.x, response.ball.y);
		});
		this.socket.on('move', response => {
			this.enemyPaddle.x = 360 - response.x;
		});
		this.socket.on('score', response => {
			this.enemyScore.setText(parseInt(response.score, 10).toString());
			this.reset();
		});
		this.socket.on('end', response => {
			this.socket.off('start');
			this.socket.off('move');
			this.socket.off('score');
			this.socket.off('end');
			this.navigate.push('/');
			//this.scene.start('EndScene', {
			//winner: response.winner,
			//});
		});
	}

	create() {
		this.initBall();
		this.initPaddle();
		this.physics.add.collider(this.ball, this.myPaddle);
		this.physics.add.collider(this.ball, this.enemyPaddle);
		this.initScore();

		this.add
			.rectangle(
				this.game.canvas.width / 2,
				this.game.canvas.height / 2,
				this.game.canvas.width,
				1,
				0xffffff,
			)
			.setOrigin(0.5, 0.5);

		if (this.input.keyboard) {
			this.keys = this.input.keyboard.createCursorKeys();
		}

		this.initSocket();
		this.reset();
	}

	update(time: number, delta: number) {
		if (!this.isPlaying) {
			if (this.room === '' || !this.keys.space?.isDown) {
				return;
			}
			return this.socket.emit('ready', {
				room: this.room,
			});
		}

		if (!this.keys || !this.myPaddle || !this.enemyPaddle) {
			return;
		}

		if (this.keys.left?.isDown) {
			this.myPaddle.setVelocityX(-400);
		} else if (this.keys.right?.isDown) {
			this.myPaddle.setVelocityX(400);
		} else {
			this.myPaddle.setVelocityX(0);
		}

		this.myPaddle.x = Phaser.Math.Clamp(
			this.myPaddle.x,
			this.myPaddle.width / 2,
			this.game.canvas.width - this.myPaddle.width / 2,
		);

		this.socket.emit('move', {
			room: this.room,
			x: this.myPaddle.x,
		});

		this.score();
	}
}

export default MainScene;
