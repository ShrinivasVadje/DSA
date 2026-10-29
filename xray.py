import tensorflow as tf
from tensorflow.keras.preprocessing.image import ImageDataGenerator
from tensorflow.keras.applications import ResNet50
from tensorflow.keras.layers import Dense, Flatten
from tensorflow.keras.models import Model

# Image preprocessing
train_gen = ImageDataGenerator(rescale=1./255, validation_split=0.2)
train_data = train_gen.flow_from_directory('dataset/train',
                                           target_size=(224,224),
                                           batch_size=32,
                                           class_mode='binary',
                                           subset='training')
val_data = train_gen.flow_from_directory('dataset/train',
                                         target_size=(224,224),
                                         batch_size=32,
                                         class_mode='binary',
                                         subset='validation')

# Load pretrained model
base_model = ResNet50(weights='imagenet', include_top=False, input_shape=(224,224,3))
for layer in base_model.layers:
    layer.trainable = False

x = Flatten()(base_model.output)
x = Dense(128, activation='relu')(x)
output = Dense(1, activation='sigmoid')(x)
model = Model(inputs=base_model.input, outputs=output)

model.compile(optimizer='adam', loss='binary_crossentropy', metrics=['accuracy'])
model.summary()

# Train model
model.fit(train_data, validation_data=val_data, epochs=10)
     

