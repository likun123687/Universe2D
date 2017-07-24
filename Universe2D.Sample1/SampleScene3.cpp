#include "Precompiled.h"
#include "SampleScene3.h"

SampleScene3::SampleScene3() : m_StartTile(nullptr), m_EndTile(nullptr) {
}
SampleScene3::~SampleScene3() {
}

bool SampleScene3::Initialize() {
	Scene::Initialize();

	MapWidth = 40;
	MapHeight = 40;

	int tileHalfWidth = IsoTile::Width / 2;
	int tileHalfHeight = IsoTile::Height / 2;

	int mapActualWidth = MapWidth * tileHalfWidth + MapHeight * tileHalfWidth;
	int mapActualHeight = MapHeight * tileHalfHeight + MapWidth * tileHalfHeight;

	int screenHalfWidth = 640;
	int screenHalfHeight = 360;

	// �� �ʱ�ȭ
	m_TileMap = new IsoTile**[MapHeight];
	for (int i = 0; i < MapHeight; i++) {
		m_TileMap[i] = new IsoTile*[MapWidth];
		for (int j = 0; j < MapWidth; j++) {
			auto tile = IsoTile::Create();

			tile->SetPosition(screenHalfWidth,
				screenHalfHeight - (mapActualHeight / 2));

			tile->Translate(j * tileHalfWidth - i * tileHalfWidth,
				i * tileHalfHeight + j * tileHalfHeight);

			tile->SetMapPosition(Vector2(j, i));

			m_TileMap[i][j] = tile;
			AddChild(tile);
		}
	}

	m_Towers = ObjecContainer::Create();
	AddChild(m_Towers);

	m_CreateTower = IsoTower::Create();
	AddChild(m_CreateTower);

	return true;
}

void SampleScene3::Update(float deltaTime) {
	Scene::Update(deltaTime);

	auto mousePosition = GetCamera()->ScreenToWorldPoint(Input::GetInstance()->GetMousePosition());

	UpdateCamera();

	// �Է�
	if (Input::GetInstance()->GetKeyState('1') == KeyState::Down) {
		m_IsCreateTower = !m_IsCreateTower;
		m_CreateTower->SetVisible(m_IsCreateTower);
	}
	// ���� ���
	if (m_IsCreateTower) {
		auto tile = GetTile(mousePosition);
		if (tile) {
			m_CreateTower->SetPosition(tile->GetPosition());

			// �ǹ� ��ġ
			if (Input::GetInstance()->GetMouseButtonState(MouseButton::Left) == KeyState::Down) {
				auto tower = IsoTower::Create();
				tower->SetPosition(m_CreateTower->GetPosition());
				tower->SetZOrder(tile->GetMapPosition().x + tile->GetMapPosition().y);

				m_Towers->AddChild(tower);
				m_Towers->SortZOrder();

				m_CreateTower->SetVisible(m_IsCreateTower);
			}
		}
	}
}

void SampleScene3::UpdateCamera() {
	if (Input::GetInstance()->GetKeyState('A') == KeyState::Pressed) {
		GetCamera()->Translate(-5, 0);
	} else if (Input::GetInstance()->GetKeyState('D') == KeyState::Pressed) {
		GetCamera()->Translate(5, 0);
	}
	if (Input::GetInstance()->GetKeyState('W') == KeyState::Pressed) {
		GetCamera()->Translate(0, -5);
	} else if (Input::GetInstance()->GetKeyState('S') == KeyState::Pressed) {
		GetCamera()->Translate(0, 5);
	}

	// Ȯ�� ���
	if (Input::GetInstance()->GetKeyState('R') == KeyState::Pressed) {
		GetCamera()->Scale(0.01f, 0.01f);
	} else if (Input::GetInstance()->GetKeyState('T') == KeyState::Pressed) {
		GetCamera()->Scale(-0.01f, -0.01f);
	}
}

IsoTile* SampleScene3::GetTile(const Vector2& position) {
	static Vector2 tileHalfSize(IsoTile::Width / 2, IsoTile::Height / 2);
	static float m = 0.5f;

	for (int i = 0; i < MapHeight; i++) {
		for (int j = 0; j < MapWidth; j++) {
			auto tile = m_TileMap[i][j];

			auto p1 = tile->GetPosition() + Vector2(-tileHalfSize.x, -tileHalfSize.y); // ��
			auto p2 = tile->GetPosition() + Vector2(0.f, -IsoTile::Height); // ��
			auto p3 = tile->GetPosition() + Vector2(tileHalfSize.x, -tileHalfSize.y); // ��
			auto p4 = tile->GetPosition() + Vector2(0.f, .0f); // ��

			float d1 = p1.y - (-m * p1.x);
			float d2 = p2.y - (m * p2.x);
			float d3 = p3.y - (-m * p3.x);
			float d4 = p4.y - (m * p4.x);

			float r1 = -m * position.x - position.y + d1;
			float r2 = m * position.x - position.y + d2;
			float r3 = -m * position.x - position.y + d3;
			float r4 = m * position.x - position.y + d4;

			if (r1 <= 0.f && r2 <= 0.f && r3 >= 0.f && r4 >= 0.f) {
				return tile;
			}
		}
	}

	return nullptr;
}
