#install.packages("ggplot2")
#install.packages("plotly")
#install.packages("dplyr")
library(ggplot2)
library(dplyr)
library(plotly)

titanic <- read.csv("Titanic_train.csv")
print(titanic)
titanic$Survived <- factor(titanic$Survived, levels = c("0", "1"))
print(titanic$Survived)

barchart = ggplot(titanic, aes(x=factor(Pclass), fill=factor(Survived)))
+geom_bar(position = "dodge")
+labs(title = "Survivors by Passenger Class", x="Passenger Class", y="Survval Count", fill="Survived")
+scale_fill_manual(values = c("0"="red", "1"="blue"))
print(barchart)

density_graph = ggplot(titanic, aes(x=Age, y=..density..))
+geom_density(fill="blue", alpha=0.5)
+labs(title = "Age distribution of passengers", x="Age", y="Density")
print(density_graph)


scatter_plot = ggplot(titanic, aes(x=Age, y=Fare, color=factor(Survived)))
+geom_point()+labs(title = "Fare vs Age", x="Age", y="Fare", color="Survived")
+scale_color_manual(values = c("0"="red", "1"="blue"))
print(scatter_plot)


heatmap = ggplot(titanic, aes(x=factor(Pclass), y=factor(Survived)))
+stat_bin_2d(bins=5, aes(fill=..count..))
+labs(title = "Titanic Survival Heatmap", x="Pclass", y="Survived", fill="Frequency")
+scale_fill_continuous(name="frequency", low="white", high="blue")+theme_minimal()
print(heatmap)

interactive_barchart = ggplotly(barchart)
print(interactive_barchart)

interactive_densitygraph = ggplotly(density_graph)
print(interactive_densitygraph)

interactive_scatter_plot = ggplotly(scatter_plot)
print(interactive_scatter_plot)

interactive_heatmap = ggplotly(heatmap)
print(interactive_heatmap)

ggsave("bar_plot.png", plot=barchart, width = 8, height = 6)
ggsave("density_graph.png", plot=density_graph, width = 8, height = 6)
ggsave("scatter_plot.png", plot=scatter_plot, width = 8, height = 6)
ggsave("heatmap.png", plot=heatmap, width = 8, height = 6)