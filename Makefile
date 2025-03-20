all: build run

build:
	docker build --platform linux/amd64 -t pbdg-rg .

run:
	docker run --platform linux/amd64 -it --rm -v $(PWD):/src pbdg-rg

prune:
	docker container prune -f

delete:
	docker rmi -f pbdg-rg
