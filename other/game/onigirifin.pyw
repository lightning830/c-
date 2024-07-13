# -*- coding: utf8 -*-
# onigiri.pyw
# 2018.9.3

import pygame
from pygame.locals import *
from pygame.locals import QUIT, K_LEFT, K_RIGHT, K_RETURN
import math
import sys
import pygame.mixer
import random
SCREEN = Rect(0, 0, 640, 480)

#BGMを鳴らす
pygame.init()

# おにぎりのクラス
class Onigiri(pygame.sprite.Sprite):
	def __init__(self, filename, soundfile, blocks, score, life):
		pygame.sprite.Sprite.__init__(self, self.containers)
		self.image = pygame.image.load(filename).convert()
		self.sound = pygame.mixer.Sound(soundfile)	# おにぎりに落下物が衝突した時の効果音取得
		self.rect = self.image.get_rect()
		self.rect.bottom = SCREEN.bottom - 20		# おにぎりのy座標
		self.rect.x = 320
		self.blocks = blocks
		self.score = score
		self.life = life
		self.size = self.image.get_size()

	def update(self):
		for event in pygame.event.get():
			if event.type == QUIT:
				pygame.quit()
				sys.exit()
			elif event.type == KEYDOWN:
				if event.key == K_LEFT:
					self.rect.x -= 4
				elif event.key == K_RIGHT:
					self.rect.x += 4
		self.rect.clamp_ip(SCREEN)					# ゲーム画面内のみで移動
		butukatta = pygame.sprite.spritecollide(self, self.blocks, True) #衝突確認リスト
		for 落ちモノ in butukatta:
			print(type(落ちモノ))
			if (isinstance(落ちモノ, 塩)):
				print("塩") #ぶつかった確認用
				self.score.addscore(100)
				self.rect.height += 20; self.rect.width += 20
				self.image = pygame.transform.scale(self.image, (self.rect.height, self.rect.width))
			elif (isinstance(落ちモノ, 梅)):
				print("梅")
				self.life.addscore(1)
			elif (isinstance(落ちモノ, のり)):
				print("海苔")
				self.score.addscore(50)
			else:					# 天ぷら
				print("天ぷら")
				self.score.addscore(200)

			del 落ちモノ
			print("play sound")
			self.sound.play()

# 落下物のクラス
class Rakka(pygame.sprite.Sprite):
	speed = 5
	def __init__(self, filename, onigiri, blocks, life):
		pygame.sprite.Sprite.__init__(self, self.containers)
		self.image = pygame.image.load(filename)
		self.rect = self.image.get_rect()
		self.rect.left = random.randrange(abs(SCREEN.width - self.rect.width))
		self.rect.bottom = SCREEN.top
		self.onigiri = onigiri						# おにぎりへの参照
		self.blocks = blocks  # ブロックグループへの参照
		self.life = life

	def update(self):
		self.rect.move_ip(0, Rakka.speed)
		# self.onigiri.sound.play()					# 反射音
		# 落ちきったら自分を削除する
		if self.rect.top > SCREEN.bottom:
			self.life.addscore(-1)
			self.rect.bottom = SCREEN.top
			del self								# オブジェクトを削除
		
class 塩(Rakka):
	def __init__(self, onigiri, blocks, life):
		super().__init__("salt.gif", onigiri, blocks, life)
		
		
class 梅(Rakka):
	def __init__(self, onigiri, blocks, life):
		super().__init__("ume.png", onigiri, blocks, life)

class のり(Rakka):
	def __init__(self, onigiri, blocks, life):
		super().__init__("nori.png", onigiri, blocks, life)

class 天ぷら(Rakka):
	def __init__(self, onigiri, blocks, life):
		super().__init__("tenpura.png", onigiri, blocks, life)

# スコアのクラス
class Score():
	def __init__(self, x, y):
		self.sysfont = pygame.font.SysFont("hg正楷書体pro", 20)		# 日本語表示用フォント
		self.sysfont.set_bold(True)							# メッセージは太字で
		self.score = 0
		(self.x, self.y) = (x, y)
		
	def draw(self, screen):
		img = self.sysfont.render("スコア:"+str(self.score), True, (255,255,250))
		screen.blit(img, (self.x, self.y))
        
	def addscore(self, x):
		 self.score += x
		 
class Life():
	def __init__(self, x, y):
		self.sysfont = pygame.font.SysFont("hg正楷書体pro", 20)		# 日本語表示用フォント
		self.sysfont.set_bold(True)							# メッセージは太字で
		self.score = 3
		(self.x, self.y) = (x, y)
	
	def draw(self, screen):
		img = self.sysfont.render("ライフ:"+str(self.score), True, (255,255,250))
		screen.blit(img, (self.x, self.y))
        
	def addscore(self, x):
		self.score += x

def main():
	while True:				# リプレイ
		pygame.init()
		clock = pygame.time.Clock()

		screen = pygame.display.set_mode(SCREEN.size)
		BG = pygame.image.load('back.png').convert()
		backrect = BG.get_rect()
		backrect.center = SCREEN.center
		endimage =  pygame.image.load("Gover.png")

		pygame.key.set_repeat(5, 5)		# キーを押し続けた時の設定（ms単位）
	 # ゲームオーバー時の効果音取得

		group = pygame.sprite.RenderUpdates()  # 描画用のスプライトグループ
		blocks = pygame.sprite.Group()	   # 衝突判定用のスプライトグループ
		Rakka.containers = group, blocks
		Onigiri.containers = group
		Rakka.containers = group, blocks
		Onigiri.containers = group

		score = Score(10, 10)
		life = Life(10, 35)
		onigiri = Onigiri("newonigiri.png", "hit.wav", blocks, score,life)
		
		print("start")
		REsound = pygame.mixer.Sound("start1.wav")
		print("over")
		GOsound = pygame.mixer.Sound("gameover.wav")
		GOsound.set_volume(0.1)
		# pygame.mixer.music.load("1214_BGM_01.mp3")
		# pygame.mixer.music.play(-1)
		
		times_rakka = 0
		gameover = replay = False
		while True:
			if not gameover:
				# 落ちモノを作成する
				if times_rakka == 0:
					#1~100でrandom、60以上で塩、40以上60未満でのり,
					r = random.randint(1,100)
					if r >= 40:
						塩(onigiri, blocks, life)	# 落ちモノは塩
					elif r >= 25 and r < 40:
						のり(onigiri, blocks, life)	# 落ちモノは海苔
					elif r < 25 and r >= 10:
						天ぷら(onigiri, blocks, life)	# 落ちモノは天ぷら
					else:
						梅(onigiri, blocks, life)	# 落ちモノは梅
				times_rakka += 1
				if times_rakka == 150:						# 150フレームにつき1個作成
					times_rakka = 0
				clock.tick(60)      # フレームレート(60fps)
				if onigiri.life.score == 0:
					gameover = True

				# screen.blit(BG, backrect)
				screen.fill((0,0,0))
				group.update()		# 全てのスプライトグループを更新
				score.draw(screen)
				life.draw(screen)
				group.draw(screen)	# 全てのスプライトグループを描画
			if gameover:
				endrect = endimage.get_rect()
				endrect.center = SCREEN.center
				screen.blit(endimage, endrect)
				# pygame.mixer.music.stop()
				GOsound.play()

				  # スコアを描画
			pygame.display.update()

			if replay:
				GOsound.stop()
				break

			for event in pygame.event.get():
				if event.type == QUIT:
					pygame.quit()
					sys.exit()
				elif event.type == KEYDOWN:
					if event.key == K_ESCAPE:
						pygame.quit()
						print("やめる")
						sys.exit()
					elif gameover and event.key == K_RETURN:
						GOsound.stop()
						REsound.play()
						replay = True
						
if __name__ == "__main__":
	main()
