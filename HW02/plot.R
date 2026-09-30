data <- read.table("results.txt")

pdf("task1.pdf")

exponents <- sequence(10:30,by=2)
ticks <- 2^exponents

plot(data$V1, data$V2,
     type="o",
     log="x",
     xlab="n",
     ylab="Time (ms)",
     main="Scan Scaling Analysis",
     xaxt="n")

axis(1, at=ticks, labels=parse(text=paste0("2^", exponents)))

dev.off()